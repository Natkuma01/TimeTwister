#include "clock.hpp"
#include <iomanip>      // required for setw() and setfill()

Clock::Clock(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
}


int validateInput(string prompt, int min, int max) {
    int input;
    bool isIntegerInRange = false;      // the input is not validated yet, so set it as false
        while (!isIntegerInRange) {     
            cout << prompt;
            cin >> input;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number." << endl;
                continue;
            }
            if (input < min || input >max) {
            cout << "Please enter a number between " << min << " and " << max << endl;
            continue;
            }
        
        return input;
        }
    return 0;
}

void Clock::displayClocks(){
    int hour12;

    hour12 = (hour % 12 == 0) ? 12 : hour % 12;
    string amPm = hour > 12 ? "PM" : "AM";
    if (hour < 10 || hour12 < 10 || minute < 10 || second < 10) {
        
    }

    cout << "***************************      ***************************" << endl;     // 27*
    cout << "*     12-Hour Clock       *      *      24-Hour Clock      *" << endl;
    cout << "*      " 
         << setw(2) << setfill('0') << hour12 << ":" 
         << setw(2) << setfill('0') << minute << ":" 
         << setw(2) << setfill('0') << second << " " << amPm << "        *";
    cout << "      ";     
    cout << "*         " 
         << setw(2) << setfill('0') << hour << ":" 
         << setw(2) << setfill('0') << minute << ":" 
         << setw(2) << setfill('0') << second << "        *" << endl;
    cout << "***************************      ***************************" << endl;     // 27*
}


void clearScreen() {
    cout << "\033[2J\033[1;1H" << flush;
}

void Clock::addHour() {
    hour = (hour + 1) % 24;
}

void Clock::addMinute() {
    minute = (minute + 1) % 60;
    if (minute == 0) {
        addHour();
    }
}

void Clock::addSecond() {
    second = (second + 1) % 60;
    if (second == 0) {
        addMinute();
    }
}