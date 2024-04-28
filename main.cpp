#include <iostream>
#include "MainMenu.h"
#include "ReadWriteFile.h"
#include <map>
using namespace std;

int main() {

    ReadInputFile(); // Initializes and formats input file data and writes to frequency.dat with the updated format

    Menu* menuPointer = new Menu(); // Initializes a new pointer reference for the Menu

    menuPointer->MainMenu(); // Calls on a referenced method MainMenu and runs that method

    return 0;
}