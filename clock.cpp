/*
* Date: 3/26/2025
* Student name: Shimin Chan
* Purpose of the project: 
* This program simulates a digital clock that allows the 
* user to set an initial time and interactively adjust hours, minutes, 
* and seconds while displaying both 12-hour and 24-hour formats.
*/

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
    bool isIntegerInRange = false;      // the input is not validated yet, so set it as false
        while (!isIntegerInRange) {     
            cout << prompt;     // Prompt user for input
            cin >> input;       // Read the input

            // Check if input is an integer
            if (cin.fail()) {
                cin.clear();        // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');    // clear the rest of the input
                cout << "Please enter a number." << endl;
                continue;       // Prompt the user again
            }
            // Check if the input is within the valid range
            if (input < min || input >max) {
            cout << "Please enter a number between " << min << " and " << max << endl;
            continue;       // Prompt the user again
            }
        
        return input;       // Return the valid input
        }
    return 0;
}

// Function to display the clock in both 12-hour and 24-hour formats
void Clock::displayClocks(){
    int hour12;

    // Convert hour to 12-hour format
    hour12 = (hour % 12 == 0) ? 12 : hour % 12;
    string amPm = hour >= 12 ? "PM" : "AM";      // Determine AM/PM based on the hour
                                                // changed operator to '>=', when it is noon, it will change to PM instead of AM

    // Format and display the time in both 12-hour and 24-hour formats
    cout << "***************************      ***************************" << endl;     // 27*
    cout << "*     12-Hour Clock       *      *      24-Hour Clock      *" << endl;
    cout << "*      " 
         << setw(2) << setfill('0') << hour12 << ":"        // Format hour in 12-hour clock
         << setw(2) << setfill('0') << minute << ":"        // Format minute
         << setw(2) << setfill('0') << second << " " << amPm << "        *";        // Format second
    cout << "      ";     
    cout << "*         " 
         << setw(2) << setfill('0') << hour << ":"          // Format hour in 24-hour clock
         << setw(2) << setfill('0') << minute << ":"        // Format minute
         << setw(2) << setfill('0') << second << "        *" << endl;               // Format second
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
    second = (second + 1) % 60;     // Add one second and ensure it wraps around at 60
    if (second == 0) {          // If seconds reset to 0, increment the minute as well
        addMinute();
    }
}