#include <iostream>
#include <cstdlib> 
#include <ctime>  
using namespace std;

int main() {
    
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to the Guess the Number Game!\n";
    cout << "Try to guess the number between 1 and 100.\n";

    do {
       
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        if (guess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else if (guess > secretNumber) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
        }

    } while (guess != secretNumber);

    return 0;
}
