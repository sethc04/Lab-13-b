#include <iostream>
#include <string>

using namespace std;

int dayOfWeek(int month, int day, int year);
int daysInMonth(int month, int year);
bool isLeapYear(int year);

const string dayNames[7] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
const string monthNames[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main() {
    string input;
    int month;
    int day;
    int year;

    do {
        cout << "Enter a date or Q to quit: ";
        getline(cin, input);
        if (input == "Q" || input == "q") {
            break;
        }

        size_t pos1 = input.find(' ');
        size_t pos2 = input.find(' ', pos1 + 1);
        if (pos1 == string::npos || pos2 == string::npos) {
            cout << "Invalid input format.\n";
            continue;
        }

        month = stoi(input.substr(0, pos1));
        day = stoi(input.substr(pos1 + 1, pos2 - pos1 - 1));
        year = stoi(input.substr(pos2 + 1));

        if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year) || year < 1) {
            cout << "Invalid date.\n";
            continue;
        }

        cout << dayNames[dayOfWeek(month, day, year)] << ", " << monthNames[month - 1] << " " << day << ", " << year << endl;
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

int dayOfWeek(int month, int day, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int h = (day + ((month + 1) * 26) / 10 + year + year / 4 + 6 * (year / 100) + year / 400) % 7;

    return h;
}