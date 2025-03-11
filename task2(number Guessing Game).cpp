#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void menu()
{
    cout << "WELCOME TO OUR NUMBER GUESSING GAME..\n\n";
    cout << "1. Easy Level" << endl;
    cout << "2. Hard Level" << endl;
    cout << "0. Exit" << endl;
}

int generateRandomNumber(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

int main()
{
    srand(time(0));
    int score = 0;
    char choice;
    do
    {
        cin.ignore();
        cin.get();
        system("clear");
        menu();
        cout << "Enter the level you want to play in: ";
        cin >> choice;
        
        switch (choice)
        {
            case '1':
            {
                system("clear");
                char easyChoice;
                int minRange, maxRange;
                int chances = 3;
                
                cout << "1. Generate a Random Number Between 1-10..\n";
                cout << "2. Generate a Random Number Between 10-30..\n";
                cout << "3. Generate a Random Number Between 30-40..\n";
                cout << "4. Generate a Random Number Between 40-50..\n";
                cout << "5. Generate a Random Number Between 50-60..\n";
                cout << "6. Generate a Random Number Between 60-100..\n";
                cout << "\nEnter the range of numbers you want to be guessed: ";
                cin >> easyChoice;
                
                switch (easyChoice)
                {
                    case '1': minRange = 1; maxRange = 10; break;
                    case '2': minRange = 10; maxRange = 30; break;
                    case '3': minRange = 30; maxRange = 40; break;
                    case '4': minRange = 40; maxRange = 50; break;
                    case '5': minRange = 50; maxRange = 60; break;
                    case '6': minRange = 60; maxRange = 100; break;
                    default: cout << "Invalid choice! Returning to main menu.\n"; continue;
                }
                
                int randomNumber = generateRandomNumber(minRange, maxRange);
                int userGuess;
                bool won = false;
                
                cout << "\nYou have " << chances << " chances to guess the number.\n";
                
                while (chances > 0)
                {
                    cout << "Enter your guess: ";
                    cin >> userGuess;
                    
                    if (userGuess == randomNumber)
                    {
                        score += 10;
                        cout << "Congratulations! You guessed the number correctly.\n Score is: " << score;
                        won = true;
                        break;
                    }
                    else if (userGuess < randomNumber)
                    {
                        cout << "Too low! Try again.\n";
                        cout << "Number has the difference between your number: " << randomNumber - userGuess << "\n";
                    }
                    else
                    {
                        cout << "Too high! Try again.\n";
                        cout << "Number has the difference between your number: " << userGuess - randomNumber << "\n";
                    }
                    chances -- ;
                }
                
                if (!won)
                {
                    cout << "Sorry, you've run out of chances. The correct number was " << randomNumber << ".\n";
                }
                break;
            }

            case '2':
            {
                system("clear");
                char hardChoice;
                int minRange, maxRange;
                int chances = 5;
                bool hintUsed = false;

                cout << "1. Generate a Random Number Between 1-100..\n";
                cout << "2. Generate a Random Number Between 100-300..\n";
                cout << "3. Generate a Random Number Between 300-500..\n";
                cout << "\nEnter the range of numbers you want to be guessed: ";
                cin >> hardChoice;

                switch (hardChoice)
                {
                    case '1': minRange = 1; maxRange = 100; break;
                    case '2': minRange = 100; maxRange = 300; break;
                    case '3': minRange = 300; maxRange = 500; break;
                    default: cout << "Invalid choice! Returning to main menu.\n"; break;
                }

                int randomNumber = generateRandomNumber(minRange, maxRange);
                int userGuess;
                bool won = false;

                cout << "\nYou have " << chances << " chances to guess the number.\n";

                while (chances > 0)
                {
                    cout << "Enter your guess: ";
                    cin >> userGuess;

                    if (userGuess == randomNumber)
                    {
                        score += 20;
                        cout << "Congratulations! You guessed the number correctly.\n Score is: " << score << endl;
                        won = true;
                        break;
                    }
                    else if (userGuess < randomNumber)
                    {
                        cout << "Too low! Try again.\n";
                    }
                    else
                    {
                        cout << "Too high! Try again.\n";
                    }

                    if (chances == 4 && !hintUsed)
                    {
                        hintUsed = true;
                        if (randomNumber % 2 == 0)
                        {
                            cout << "Hint: The number is even.\n";
                        }
                        else
                        {
                            cout << "Hint: The number is odd.\n";
                        }
                    }
                    else if (chances == 2)
                    {
                        cout << "As you haven't guessed the number yet, here's a better hint. Score will be halved.\n";
                        cout << "The difference between your guess and the number is: " << randomNumber - userGuess << "\n";
                        score /= 2;
                    }

                    chances--;
                }

                if (!won)
                {
                    cout << "Sorry, you've run out of chances. The correct number was " << randomNumber << ".\n";
                }
                break;
            }

            default:
                cout << "Invalid Input. Enter your input again.. \n";
                break;
        }
    } while (choice != '0');
    
    cout << "Thank you for playing!\n";
    return 0;
}
