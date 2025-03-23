#ifndef CLOCK_H     // Include guard to prevent multiple inclusions of this header file
#define CLOCK_H


#include <iostream>
#include <limits>       // for cin.ignore(), clear the rest of input
#include <string>

using namespace std;

// Clock class definition
class Clock {
private:
    int hour;           // Variable to store the hour (0-23)
    int minute;         // Variable to store the minute (0-59)
    int second;         // Variable to store the minute (0-59)

public:
    // Constructor to initialize the clock with default values of 0 for hour, minute, and second
    // Parameters can be provided during object creation, otherwise default to 0
    Clock(int h = 0, int m = 0, int s = 0);

    void displayClocks();      // Function to display the current time in both 12-hour and 24-hour formats
    void addHour();         // Function to add one hour to the current time
    void addMinute();        // Function to add one minute to the current time
    void addSecond();        // Function to add one second to the current time
};

// Function to validate user input, ensuring it is within a given range
int validateInput(string prompt, int min, int max);

// Function to clear the console screen using ANSI escape codes
void clearScreen();

#endif