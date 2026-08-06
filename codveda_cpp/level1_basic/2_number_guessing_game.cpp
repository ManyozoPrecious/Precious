 

#include <iostream>
#include <random>
#include <limits>

const int MIN_NUMBER = 1;
const int MAX_NUMBER = 100;
const int MAX_ATTEMPTS = 7;

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(MIN_NUMBER, MAX_NUMBER);
    int target = dist(gen);

    int guess;
    int attempts = 0;
    bool won = false;

    std::cout << "__Number Guessing Game__\n";
    std::cout << "I'm thinking of a number between " << MIN_NUMBER
               << " and " << MAX_NUMBER << ".\n";
    std::cout << "You have " << MAX_ATTEMPTS << " attempts. Good luck!\n\n";

    while (attempts < MAX_ATTEMPTS) {
        std::cout << "Attempt " << attempts + 1 << "/" << MAX_ATTEMPTS
                   << " - Enter your guess: ";

        if (!(std::cin >> guess)) {
            std::cout << "Invalid input, please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        attempts++;

        if (guess < target) {
            std::cout << "Too low!\n\n";
        } else if (guess > target) {
            std::cout << "Too high!\n\n";
        } else {
            won = true;
            break;
        }
    }

    if (won) {
        std::cout << "Congratulations! You guessed the number " << target
                   << " correctly in " << attempts << " attempt(s).\n";
    } else {
        std::cout << "Sorry, you're out of attempts. The number was " << target << ".\n";
    }

    return 0;
}
