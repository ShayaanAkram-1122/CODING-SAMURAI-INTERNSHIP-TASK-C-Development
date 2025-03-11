#include<iostream>
using namespace std;

void menu() {
    cout << "BASIC ARITHMETIC CALCULATOR...." << endl << endl;
    cout << "1.ADDITION" << endl;
    cout << "2.SUBTRACTION" << endl;
    cout << "3.MULTIPLICATION" << endl;
    cout << "4.DIVISION" << endl;
    cout << "0.EXIT THE CALCULATOR" << endl;
    cout << "Enter your choice of the operations you want: ";
}

int main() {
    char choice;
    do {
        menu();
        cin >> choice;
        system("clear");

        switch (choice) {
            case '1': {
                long double a, b;
                cout << "Enter two Numbers: ";
                cin >> a >> b;
                long double r = a + b;
                cout << "Result is: " << r << endl;
            }
            break;

            case '2': {
                long double a, b;
                cout << "Enter two Numbers: ";
                cin >> a >> b;
                long double r = a - b;
                cout << "Result is: " << r << endl;
            }
            break;

            case '3': {
                long double a, b;
                cout << "Enter two Numbers: ";
                cin >> a >> b;
                long double r = a * b;
                cout << "Result is: " << r << endl;
            }
            break;

            case '4': {
                long double a, b;
                cout << "Enter two Numbers: ";
                cin >> a >> b;

                while (b == 0) { 
                    cout << "Invalid input for denominator, enter again: ";
                    cin >> b;
                }

                long double r = a / b;
                cout << "Result is: " << r << endl;
            }
            break;

            case '0':
                cout << "Exiting the calculator..." << endl;
                break;

            default:
                cout << "Invalid Input...\n";
                break;
        }

        cin.ignore(); 
        cin.get();   
        system("clear");

    } while (choice != '0'); 

    return 0;
}
