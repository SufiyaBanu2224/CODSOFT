#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); 
    int number = rand() % 100 + 1; 
    int guess = 0;
    cout << "Guess the number between 1 and 100: ";

    while (guess != number) {
        cin >> guess;
        if (guess >= number+10) {
            cout << "Too high!\nTry again: ";
        }else if (guess > number && guess<number+10) {
            cout << "Little High!\nTry again: ";
        }else if (guess <= number-10) {
            cout << "Too low!\nTry again: ";
        }else if (guess < number && guess > number-10) {
            cout << "Little low!\nTry again: ";
        } else{
            cout << "Congratulations! You guessed the number.\n";
        }
    }

    return 0;
}
