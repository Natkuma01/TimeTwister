#include <iostream>
#include "clock.hpp"        // Include the header for the Clock class
#include "clock.cpp"
#include <thread>           // for pausing execution
#include <chrono>           // for time-related functions
using namespace std;

// declare all functions
void displayMenu();
void runClockProgram(Clock& initialTime);
int validateInput(string prompt, int min, int max);
void clearScreen();

void displayMenu() {
    // Display a menu for user interaction
    cout << "***************************" << endl;
    cout << "*  1 - Add One Hour       *" << endl;
    cout << "*  2 - Add One Minute     *" << endl;
    cout << "*  3 - Add One Second     *" << endl;
    cout << "*  4 - Exit Program       *" << endl;
    cout << "***************************" << endl;
    cout << "Please make your selection: ";
}

// Function to run the main clock interaction loop
void runClockProgram(Clock& initialTime) {
    int choice;

    do { 
        clearScreen();
        
        initialTime.displayClocks();
        displayMenu();     

        cin >> choice;      // Take user input for menu selection
        if (cin.fail() || choice < 1 || choice > 4) {       
            cin.clear();       
            cin.ignore(numeric_limits<streamsize>::max(), '\n');        
            cout << "Invalid choice. Please enter any number between 1 - 4." << endl;
            // Pause for 1 second before continuing
            // Purpose: allow user to follow the program's actions in a more manageable pace
            this_thread::sleep_for(chrono::seconds(1));     
            continue;       // Skip the rest of the loop and start over
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
            this_thread::sleep_for(chrono::seconds(1));     // Pause 1 second before exiting
            cout << "GoodBye!" << endl;
            break;
            default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice !=4);   

}

int main() {
    int hour;
    int minute;
    int second;
    int choice;

    // Prompt the user to enter initial values for hour, minute, and second
    hour = validateInput("Enter the initial hour: ", 0 ,23);
    minute = validateInput("Enter the initial minute: ", 0 ,59);
    second = validateInput("Enter the initial second: ", 0 ,59);

    Clock initialTime(hour, minute, second);    

    cout << endl;

    // Start the clock program
    runClockProgram(initialTime);

    return 0;
}