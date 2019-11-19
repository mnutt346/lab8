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

    // Print the values of each sorted array
    cout << endl
         << "Sorted numbers.txt: ";
    for (int i = 0; i < numbersArrayLength; i++)
    {
        cout << numbersArray[i] << " ";
    }

    cout << endl
         << "Sorted early.txt: ";
    for (int i = 0; i < earlyArrayLength; i++)
    {
        cout << earlyArray[i] << " ";
    }

    cout << endl
         << "Sorted mid.txt: ";
    for (int i = 0; i < midArrayLength; i++)
    {
        cout << midArray[i] << " ";
    }

    cout << endl
         << "Sorted end.txt: ";
    for (int i = 0; i < endArrayLength; i++)
    {
        cout << endArray[i] << " ";
    }
}