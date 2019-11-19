/**************************************************************************************
** Program name: driver.cpp
** Author: Michael Nutt
** Date: 11/19/2019
** Description: Implementation file for the driver function.
**************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "driver.hpp"
#include "fileReader.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

void driver()
{
    // Get the lengths of each file
    int numbersArrayLength = getFileLength("numbers.txt");
    int earlyArrayLength = getFileLength("early.txt");
    int midArrayLength = getFileLength("mid.txt");
    int endArrayLength = getFileLength("end.txt");

    // Initialize empty arrays for each file with their respective lengths
    int *numbersArray = new int[numbersArrayLength];
    int *earlyArray = new int[earlyArrayLength];
    int *midArray = new int[midArrayLength];
    int *endArray = new int[endArrayLength];

    // Read contents of each file into its respective array
    fileReader("numbers.txt", numbersArray);
    fileReader("early.txt", earlyArray);
    fileReader("mid.txt", midArray);
    fileReader("end.txt", endArray);

    // Prompt user for an integer
    string option = "a target value";
    int targetNum = gameMenuRange(option, 0, 10);
}