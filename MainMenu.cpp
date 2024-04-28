#include <iostream>
#include <iomanip>
#include "MainMenu.h"
#include "ItemSearch.h"
#include "ReadWriteFile.h"
using namespace std;

// Used to print a menu to the console for users view
void Menu::PrintMenu() {
    cout << "Please select an option to continue by typing a number 1-4." << endl;
    cout << setfill('=') << setw(75) << "" << endl;
    cout << "1: Search number of occurances for a single item" << endl;
    cout << "2: Get a printed list of items and the number of occurances in a plain report" << endl;
    cout << "3: Get a printed list of items and the number of occurances in a histogram style report" << endl;
    cout << "4: Quit Program" << endl;
    cout << endl;
}

// Initializes the MainMenu and processes the users input for option selections
void Menu::MainMenu() {

    while (m_option != 4) {
        PrintMenu(); // Prints the main menu

        cout << "Your Intput: ";
        cin >> m_option; // Gets user input
        cout << endl;

        // Validates users input with the corresponding options
        switch (m_option) {
        case 1:
            ItemSearch(); // Calls and runs the ItemSearch function
            break;
        case 2:
            PrintFrequencyFile(); // Calls and runs the PrintFrequencyFile function
            break;
        case 3:
            PrintHistogramReport(); // Calls and runs the PrintHistogramReport function
            break;
        case 4:
            // This option ends the program
            cout << "Goodbye";
            break;
        default:
            // BUG: When anything but an int is inputted by user, main menu recursively runs with this default option always printing. (Not sure how to fix...)

            // This option is used for any other number inputted by the user
            cout << "Invalid option. Please select a number 1-4 by typing that number. Ex. '4' will quit the program." << endl;
            cout << endl;
            break;
        }
    }
}