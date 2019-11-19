/**************************************************************************************
** Program name: filePrinter.cpp
** Author: Michael Nutt
** Date: 11/19/2019
** Description: Implementation file for the filePrinter function.
**************************************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#include "filePrinter.hpp"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/* Summary: Prints the contents of the given file to the screen.
 * Param: string fileName -> name of file from which data is read
 * Return: N/A
 */
void filePrinter(string fileName)
{
    ifstream fin(fileName);

    int number;

    cout << endl
         << "Sorted " << fileName << ": ";

    while (fin >> number)
    {
        cout << number << " ";
    }

    fin.close();
}