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
#include "simpleSearch.hpp"
#include "quickSort.hpp"
#include "fileWriter.hpp"
#include "filePrinter.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;
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

    // Search each file for the target number
    bool foundInNumbers = simpleSearch(numbersArray, numbersArrayLength, targetNum);
    bool foundInEarly = simpleSearch(earlyArray, earlyArrayLength, targetNum);
    bool foundInMid = simpleSearch(midArray, midArrayLength, targetNum);
    bool foundInEnd = simpleSearch(endArray, endArrayLength, targetNum);

    // Print whether the target was found in each file
    string found = "target value found";
    string notFound = "target value not found";

    cout << "numbers.txt: " << (foundInNumbers ? found : notFound) << endl
         << "early.txt: " << (foundInEarly ? found : notFound) << endl
         << "mid.txt: " << (foundInMid ? found : notFound) << endl
         << "end.txt: " << (foundInEnd ? found : notFound) << endl;

    // Sort the values in the arrays
    quickSort(numbersArray, 0, numbersArrayLength - 1);
    quickSort(earlyArray, 0, earlyArrayLength - 1);
    quickSort(midArray, 0, midArrayLength - 1);
    quickSort(endArray, 0, endArrayLength - 1);

    // Prompt user for names of output files
    string numbersOutName = getOutFileName("numbers.txt");
    string earlyOutName = getOutFileName("early.txt");
    string midOutName = getOutFileName("mid.txt");
    string endOutName = getOutFileName("end.txt");

    // Write sorted numbers to their respective files
    fileWriter(numbersOutName, numbersArray, numbersArrayLength);
    fileWriter(earlyOutName, earlyArray, earlyArrayLength);
    fileWriter(midOutName, midArray, midArrayLength);
    fileWriter(endOutName, endArray, endArrayLength);

    // Print the values of each file
    filePrinter(numbersOutName);
    filePrinter(earlyOutName);
    filePrinter(midOutName);
    filePrinter(endOutName);
}