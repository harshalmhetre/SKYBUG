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
            cout << " low! Try again.\n";
        } else if (guess > secretNumber) {
            cout << " high! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
        }

    } while (guess != secretNumber);

    return 0;
}


//OUTPUT
/*Welcome to the Guess the Number Game!
Try to guess the number between 1 and 100.
Enter your guess: 15
 low! Try again.
Enter your guess: 25
 low! Try again.
Enter your guess: 35
 low! Try again.
Enter your guess: 55
 low! Try again.
Enter your guess: 61
 low! Try again.
Enter your guess: 75
 high! Try again.
Enter your guess: 70
 high! Try again.
Enter your guess: 65
 low! Try again.
Enter your guess: 68
Congratulations! You guessed the correct number in 9 attempts.*/
