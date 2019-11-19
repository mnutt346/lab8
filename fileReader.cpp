/**************************************************************************************
** Program name: fileReader.cpp
** Author: Michael Nutt
** Date: 11/19/2019
** Description: Implementation file for the file-reading function.
**************************************************************************************/
#include <fstream>
#include <string>
#include "fileReader.hpp"

using std::ifstream;
using std::string;

int getFileLength(string fileName)
{
    int length = 0;

    ifstream fin(fileName);

    int number;

    // While there are still numbers in the file
    while (fin >> number)
    {
        // Increment the length
        length++;
    }

    fin.close();

    return length;
}

void fileReader(string fileName, int *someArray)
{
    ifstream fin(fileName);
    int number;
    int fIndex = 0;

    // Read file contents into the array passed in
    while (fin >> number)
    {
        someArray[fIndex] = number;

        fIndex++;
    }

    fin.close();
}
