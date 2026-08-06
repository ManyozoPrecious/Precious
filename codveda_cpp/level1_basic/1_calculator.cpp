 

#include <iostream>
#include <iomanip>

int main() {
    double num1, num2, result;
    char op;

    std::cout << "===== Simple Calculator =====\n";
    std::cout << "Enter first number: ";
    if (!(std::cin >> num1)) {
        std::cout << "Invalid input.\n";
        return 1;
    }

    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    if (!(std::cin >> num2)) {
        std::cout << "Invalid input.\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(2);

    switch (op) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n";
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n";
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n";
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed.\n";
                return 1;
            }
            result = num1 / num2;
            std::cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
            break;
        default:
            std::cout << "Error: Invalid operator '" << op << "'. Use +, -, *, or /.\n";
            return 1;
    }

    return 0;
}
