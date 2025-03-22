#ifndef CLOCK_H
#define CLOCK_H


#include <iostream>
#include <limits>
#include <string>

using namespace std;



class Clock {
private:
    int hour;
    int minute;
    int second;

public: 
    Clock(int h = 0, int m = 0, int s = 0);

    void displayClocks();
    void addHour();
    void addMinute();
    void addSecond();
};


int validateInput(string prompt, int min, int max);

void clearScreen();


#endif