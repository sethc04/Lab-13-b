
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int dayOfWeek(int month, int day, int year);
int daysInMonth(int month, int year);
bool isLeapYear(int year);

const string dayNames[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
const string monthNames[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main() {
    string input;
    string monthName;
    int year;

    cout << "Enter a month and year or Q to quit: ";
    getline(cin, input);

    if (input == "Q" || input == "q")
        return 0;

    istringstream iss(input);
    iss >> monthName >> year;

    int month = -1;
    for (int i = 0; i < 12; ++i) {
        if (monthNames[i] == monthName) {
            month = i + 1;
            break;
        }
    }

    if (month == -1) {
        cout << "Invalid month.\n";
        return 1;
    }

    int firstDay = dayOfWeek(month, 1, year);

    cout << monthName << " " << year << endl;
    cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;

    int days = daysInMonth(month, year);
    int currentDay = 1;

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (i == 0 && j < firstDay)
                cout << "    ";
            else if (currentDay <= days) {
                cout.width(4);
                cout << currentDay++;
            }
            else
                break;

            if (currentDay > days)
                break;
        }
        cout << endl;
    }

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

    int h = (day - 1 + ((month + 1) * 26) / 10 + year + year / 4 + 6 * (year / 100) + year / 400) % 7;

    return h;
}
