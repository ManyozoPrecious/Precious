 

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

const int BUFFER_SIZE = 5;
const int ITEMS_TO_PRODUCE = 10;

std::queue<int> buffer;
std::mutex mtx;
std::condition_variable notFull;
std::condition_variable notEmpty;

void producer() {
    for (int i = 1; i <= ITEMS_TO_PRODUCE; i++) {
        std::unique_lock<std::mutex> lock(mtx);

        // Wait while the buffer is full
        notFull.wait(lock, [] { return buffer.size() < BUFFER_SIZE; });

        buffer.push(i);
        std::cout << "[Producer] produced item " << i
                   << " (buffer size: " << buffer.size() << ")\n";

        lock.unlock();
        notEmpty.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void consumer() {
    for (int i = 1; i <= ITEMS_TO_PRODUCE; i++) {
        std::unique_lock<std::mutex> lock(mtx);

        // Wait while the buffer is empty
        notEmpty.wait(lock, [] { return !buffer.empty(); });

        int item = buffer.front();
        buffer.pop();
        std::cout << "                [Consumer] consumed item " << item
                   << " (buffer size: " << buffer.size() << ")\n";

        lock.unlock();
        notFull.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
}

int main() {
    std::cout << "===== Producer-Consumer Simulation =====\n";
    std::cout << "Buffer size: " << BUFFER_SIZE
               << ", Items to produce: " << ITEMS_TO_PRODUCE << "\n\n";

    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout << "\nAll items produced and consumed. Done.\n";
    return 0;
}
