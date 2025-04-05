#include "clock.hpp"
#include <iomanip>      // required for setw() and setfill()

// Constructor to initialize the clock with hour, minute, and second
Clock::Clock(int hours, int minutes, int seconds) {
    hour = hours;
    minute = minutes;
    second = seconds;
}

// Function to validate user input, ensuring it is within a specified range
int validateInput(string prompt, int min, int max) {
    int input;
    bool isIntegerInRange = false;      
        while (!isIntegerInRange) {     
            cout << prompt;     
            cin >> input;      

            // Check if input is an integer
            if (cin.fail()) {
                cin.clear();        
                cin.ignore(numeric_limits<streamsize>::max(), '\n');    // clear the rest of the input
                cout << "Please enter a number." << endl;
                continue;       // Prompt the user again
            }
            // Check if the input is within the valid range
            if (input < min || input >max) {
            cout << "Please enter a number between " << min << " and " << max << endl;
            continue;       
            }
        
        return input;       
        }
    return 0;
}

// Function to display the clock in both 12-hour and 24-hour formats
void Clock::displayClocks(){
    int hour12;

    // Convert hour to 12-hour format
    hour12 = (hour % 12 == 0) ? 12 : hour % 12;
    string amPm = hour >= 12 ? "PM" : "AM";      

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
    cout << "***************************      ***************************" << endl;     
}

// Function to clear the console screen using ANSI escape codes
void clearScreen() {
    cout << "\033[2J\033[1;1H" << flush;
}

// Function to add one hour to the initial time 
void Clock::addHour() {
    hour = (hour + 1) % 24;     // Add one hour and ensure the hour wraps around at 24
}

// Function to add one minute to the initial time
void Clock::addMinute() {
    minute = (minute + 1) % 60;     // Add one minute and ensure it wraps around at 60
    if (minute == 0) {          // If minutes reset to 0, increment the hour as well
        addHour();
    }
}

// Function to add one second to the current time
void Clock::addSecond() {
    second = (second + 1) % 60;     
    if (second == 0) {          
        addMinute();
    }
}