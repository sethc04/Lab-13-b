#include <iostream>

using namespace std;

bool isLeapYear(int year);

int main() {
    char input;
    do {
        int year;
        cout << "Enter a year or Q to quit: ";
        cin >> input;
        if (toupper(input) == 'Q') {
            break;
        }
        cin >> year;

        if (isLeapYear(year)) {
            cout << "It is a leap year." << endl;
        }
        else {
            cout << "It is not a leap year." << endl;
        }
    } while (true);

    return 0;
}


bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}
