#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);

int main() {
    string input;
    int month;
    int year;
    const string monthNames[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    do {
        cout << "Enter a month and year or Q to quit: ";
        getline(cin, input);
        if (input == "Q" || input == "q") {
            break;
        }

        if (input.length() == 7) {
            month = stoi(input.substr(0, 2));
            year = stoi(input.substr(3, 4));
        }
        else if (input.length() == 6) {
            month = stoi(input.substr(0, 1));
            year = stoi(input.substr(2, 4));
        }


        if (month < 1 || month > 12) {
            cout << "Invalid month.\n";
            continue;
        }

        cout << monthNames[month - 1] << " " << year << " has " << daysInMonth(month, year) << " days." << endl;
    } while (true);

    return 0;
}

int daysInMonth(int month, int year) {
    switch (month) {
    case 2:
        return isLeapYear(year) ? 29 : 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
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
