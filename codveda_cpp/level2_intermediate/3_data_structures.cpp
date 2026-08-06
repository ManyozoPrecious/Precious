 

#include <iostream>
#include <limits>

struct Node {
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

// ================= STACK (linked-list based) =================
class Stack {
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        int dummy;
        while (pop(dummy)) { /* free all remaining nodes */ }
    }

    void push(int value) {
        Node *node = new Node(value);
        node->next = top;
        top = node;
        std::cout << "Pushed " << value << " onto the stack.\n";
    }

    bool pop(int &outValue) {
        if (top == nullptr) return false; // empty
        Node *temp = top;
        outValue = temp->data;
        top = temp->next;
        delete temp;
        return true;
    }

    void display() const {
        if (top == nullptr) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "Stack (top -> bottom): ";
        for (Node *cur = top; cur != nullptr; cur = cur->next) {
            std::cout << cur->data << " ";
        }
        std::cout << "\n";
    }
};

// ================= QUEUE (linked-list based) =================
class Queue {
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        int dummy;
        while (dequeue(dummy)) { /* free all remaining nodes */ }
    }

    void enqueue(int value) {
        Node *node = new Node(value);
        if (rear == nullptr) {
            front = rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
        std::cout << "Enqueued " << value << ".\n";
    }

    bool dequeue(int &outValue) {
        if (front == nullptr) return false; // empty
        Node *temp = front;
        outValue = temp->data;
        front = temp->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        return true;
    }

    void display() const {
        if (front == nullptr) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Queue (front -> rear): ";
        for (Node *cur = front; cur != nullptr; cur = cur->next) {
            std::cout << cur->data << " ";
        }
        std::cout << "\n";
    }
};

// ================= MENU =================
int main() {
    Stack stack;
    Queue queue;
    int choice, value;

    do {
        std::cout << "\n===== Data Structures Demo =====\n";
        std::cout << "1. Stack Push\n";
        std::cout << "2. Stack Pop\n";
        std::cout << "3. Stack Display\n";
        std::cout << "4. Queue Enqueue\n";
        std::cout << "5. Queue Dequeue\n";
        std::cout << "6. Queue Display\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose an option: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Enter a value to push: ";
                std::cin >> value;
                stack.push(value);
                break;
            case 2:
                if (stack.pop(value))
                    std::cout << "Popped " << value << " from the stack.\n";
                else
                    std::cout << "Stack is empty, nothing to pop.\n";
                break;
            case 3:
                stack.display();
                break;
            case 4:
                std::cout << "Enter a value to enqueue: ";
                std::cin >> value;
                queue.enqueue(value);
                break;
            case 5:
                if (queue.dequeue(value))
                    std::cout << "Dequeued " << value << " from the queue.\n";
                else
                    std::cout << "Queue is empty, nothing to dequeue.\n";
                break;
            case 6:
                queue.display();
                break;
            case 7:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, try again.\n";
        }
    } while (choice != 7);

    return 0;
}
