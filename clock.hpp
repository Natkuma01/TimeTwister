/*
* Date: 3/26/2025
* Student name: Shimin Chan
* Purpose of the project: 
* This program simulates a digital clock that allows the 
* user to set an initial time and interactively adjust hours, minutes, 
* and seconds while displaying both 12-hour and 24-hour formats.
*/
#pragma once        // ensure this file is included one time during compilation

#ifndef CLOCK_H     // Include guard to prevent multiple inclusions of this header file
#define CLOCK_H


#include <iostream>
#include <limits>       // for cin.ignore(), clear the rest of input
#include <string>

using namespace std;


class Clock {
private:
    int hour;               // >> private, CamelCase
    int minute;         
    int second;         

public:
    // Constructor to initialize the clock with default values of 0 for hour, minute, and second
    // Parameters can be provided during object creation, otherwise default to 0
    Clock(int h = 0, int m = 0, int s = 0);

    void displayClocks();      
    void addHour();         
    void addMinute();        
    void addSecond();        
};

// Function to validate user input, ensuring it is within a given range
int validateInput(string prompt, int min, int max);


void clearScreen();

#endif