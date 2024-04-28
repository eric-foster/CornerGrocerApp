#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

void ItemSearch() {
    ifstream itemData; // Initializes input stream
    string userword; // Initializes a string called userword - used for user input
    string wordFrequency = " 0"; // Initializes a string called wordFrequency - used to keep track of the number of occurences seen in the specified file
    string currentWord; // Initializes a temp variable to hold the current word the stream is reading from the file

    itemData.open("frequency.dat"); // Opens the specified file

    // Validates if file successfully opened
    if (!itemData.is_open()) {
        cout << "Could not open file numFile.txt." << endl;
    }
    else { // Executes else statement if file opened successfully
        cout << "Enter am item you would like to see data on: ";
        cin >> userword; // Gets user input for search word

        // Turns user input into lowercase so that case sensitivity is ignored
        for (auto& character : userword) {
            character = tolower(character);
        }

        // Reads until the end of file
        while (!itemData.eof()) {
            itemData >> currentWord; // Gets the first word of each line in the file

            // Turns input into lowercase so that case sensitivity is ignored
            for (auto& character : currentWord) {
                character = tolower(character);
            }

            if (!itemData.fail()) {
                if (currentWord == userword) { // Checks if the currentword and the user input match - if so, code block runs
                    getline(itemData, wordFrequency); // Gets the current line and assigns the number associated with the search word to the wordFrequency variable
                }
            }
        }

        cout << userword << " appears in the file" << wordFrequency << " times." << endl << endl; // Outputs the newly gathered data to the console
    }

    itemData.close();
}