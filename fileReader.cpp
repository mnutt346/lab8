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

/* Summary: Gets the length of the given file
 * Param: string fileName -> name of file to be read
 * Return: integer value representing the length of the file
 */
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

/* Summary: Reads the values fromthe target file and adds them to the given array
 * Param: string fileName -> the name of the file from which the data is read
 * Param: int *targetArray -> the array to which the data will be copied
 * Return: N/A
 */
void fileReader(string fileName, int *targetArray)
{
    ifstream fin(fileName);
    int number;
    int fIndex = 0;

    // Read file contents into the array passed in
    while (fin >> number)
    {
        targetArray[fIndex] = number;

        fIndex++;
    }

    fin.close();
}
