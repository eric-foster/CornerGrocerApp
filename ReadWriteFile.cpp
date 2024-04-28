#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;

void WriteFile(map<string, int> itemFrequencyList) {
    ofstream frequencyData; // Initializes output file stream

    frequencyData.open("frequency.dat"); // Opens/creates the specified file

    // Validates file successfully opens
    if (!frequencyData.is_open()) {
        cout << "Could not open file..." << endl;
    }
    else {
        // Iterates over each key: value pair and prints that in a single line
        for (const auto& value : itemFrequencyList) {
            frequencyData << value.first << " " << value.second << endl;
        }

        frequencyData.close(); // Closes file stream
    }
}

void ReadInputFile() {
    // Initializes variables and a map
    string item;
    map<string, int> itemFrequency;
    int count = 1;

    ifstream inputFile; // Initializes Input file stream

    inputFile.open("InputFile.txt"); // Opens specified file

    // Validates if file opened successfully
    if (!inputFile.is_open()) {
        cout << "Could not open file..." << endl;
    }
    else {
        inputFile >> item; // Gets line input from the input file stream

        while (!inputFile.fail()) {
            itemFrequency.emplace(item, count); // Places each item in a map variable with a pre-defined initial count of 0

            // Checks if the item is already in the map
            if (itemFrequency.at(item)) {
                itemFrequency.at(item) = itemFrequency.at(item) + 1; // Adds one to the value of the specified key (item)
            }

            inputFile >> item; // Continues to read the next line and repeats until end of file
        }

        if (!inputFile.eof()) {
            cout << "Input failure before reaching end of file..." << endl;
        }

        inputFile.close(); // Closes input file stream

        WriteFile(itemFrequency); // Calls and runs the function
    }
}

void PrintFrequencyFile() {
    string line; // Initializes variable
    ifstream frequencyFile; // Initializes Input stream

    frequencyFile.open("frequency.dat");// Opens specified file

    // Validates if file opened successfully
    if (!frequencyFile.is_open()) {
        cout << "Could not open file..." << endl;
    }
    else {

        while (!frequencyFile.fail()) {

            // Gets each line in full from the input file and prints that line
            while (getline(frequencyFile, line)) {
                cout << line << endl;
            }

        }

        if (!frequencyFile.eof()) {
            cout << "Input failure before reaching end of file..." << endl;
        }

        cout << endl;
        frequencyFile.close(); // Closes input file stream
    }
}

void PrintHistogramReport() {
    string line;
    ifstream frequencyFile;

    frequencyFile.open("frequency.dat");// Opens specified file

    // Validates if file opened successfully
    if (!frequencyFile.is_open()) {
        cout << "Could not open file..." << endl;
    }
    else {

        while (!frequencyFile.fail()) {

            while (getline(frequencyFile, line)) {
                // Initializes variables
                istringstream iss(line); // Initializes a string stream to enable extraction of specific parts of the line
                string name;
                int num;

                // Checks for a line and prints the name of the item and the number of occurances in asterisks
                if (iss >> name >> num) {
                    cout << name << " ";

                    for (int i = 0; i < num; i++) {
                        cout << "*";
                    }

                    cout << endl;
                }
            }
        }

        while (!frequencyFile.eof()) {
            cout << "Input failure before reaching end of file..." << endl;
        }

        cout << endl;
        frequencyFile.close(); // Closes input file stream
    }
}