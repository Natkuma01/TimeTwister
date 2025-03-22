#include <iostream>
#include "clock.hpp"
#include "clock.cpp"
#include <thread>
#include <chrono>
using namespace std;


void displayMenu() {
    cout << "***************************" << endl;
    cout << "*  1 - Add One Hour       *" << endl;
    cout << "*  2 - Add One Minute     *" << endl;
    cout << "*  3 - Add One Second     *" << endl;
    cout << "*  4 - Exit Program       *" << endl;
    cout << "***************************" << endl;
    cout << "Please make your selection: ";
}


int main() {
    int hour;
    int minute;
    int second;
    int choice;

    hour = validateInput("Enter the initial hour: ", 0 ,23);
    minute = validateInput("Enter the initial minute: ", 0 ,59);
    second = validateInput("Enter the initial second: ", 0 ,59);

    Clock initialTime(hour, minute, second);
    

    cout << endl;

    do { 
        
        initialTime.displayClocks();
        displayMenu();

        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter any number between 1 - 4." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            continue;
        }
        switch(choice) {
            case 1:
            initialTime.addHour();
            break;
            case 2:
            initialTime.addMinute();
            break;
            case 3:
            initialTime.addSecond();
            break;
            case 4:
            clearScreen();
            cout << "Exiting the program..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "GoodBye!" << endl;
            break;
            default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice !=4);

    return 0;
}