#include <iostream>
#include <string>

using namespace std;

int dayOfWeek(int month, int day, int year);
int daysInMonth(int month, int year);
bool isLeapYear(int year);

const string dayNames[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
const string monthNames[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const string calendar[] = {
    " Su Mo Tu We Th Fr Sa ",
    "    1  2  3  4  5  6 ",
    "  7  8  9 10 11 12 13 ",
    " 14 15 16 17 18 19 20 ",
    " 21 22 23 24 25 26 27 ",
    " 28 29 30 31          "
};

int main() {
    string input;
    int month;
    int year;

    do {
        cout << "Enter a month and year or Q to quit: ";
        getline(cin, input);
        if (input == "Q" || input == "q") {
            break;
        }

        size_t pos = input.find(' ');
        if (pos == string::npos) {
            cout << "Invalid input format.\n";
            continue;
        }

        month = stoi(input.substr(0, pos));
        year = stoi(input.substr(pos + 1));

        if (month < 1 || month > 12 || year < 1) {
            cout << "Invalid month or year.\n";
            continue;
        }

        cout << monthNames[month - 1] << " " << year << endl;

        int firstDayOfWeek = dayOfWeek(month, 1, year);

        for (int i = 0; i < 6; ++i) {
            cout << calendar[i].substr(3 * firstDayOfWeek, 21) << endl;
            firstDayOfWeek = 0; // For subsequent lines, start from Sunday
        }

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
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int dayOfWeek(int month, int day, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int h = (day + ((month + 1) * 26) / 10 + year + year / 4 + 6 * (year / 100) + year / 400) % 7;

    return h;
}