#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;

    switch (op) {
        case '+':
            out << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << std::endl;
            else
                cout << "Error: Division by zero.\n";
            break;
        default:
            cout << "Error: Invalid operator.\n";
    }

    return 0;
}
