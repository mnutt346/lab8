/**************************************************************************************
** Program name: fileWriter.hpp
** Author: Michael Nutt
** Date: 11/19/2019
** Description: Implementation file for the file-writing function.
**************************************************************************************/
#include <string>
#include <fstream>
#include <iostream>
#include "fileWriter.hpp"
#include "inputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;

/* Summary: Writes the contents of the given array to the output file of the given name
 * Param: string outFileName -> name to be used for the output file
 * Param: int *targetArray -> array of integers to be copied
 * Param: int arrayLength -> length of the given array
 * Return: N/A
 */
void fileWriter(string outFileName, int *targetArray, int arrayLength)
{
    cout << "Writing to " << outFileName << "..." << endl;

    ofstream fout(outFileName);

    for (int i = 0; i < arrayLength; i++)
    {
        fout << targetArray[i] << " ";
    }

    fout.close();
}

/* Summary:Gets the file name to be used for the output file
 * Param: string inFileName -> name of the corresponding input file
 * Return: string value representing the name of the new output file
 */
string getOutFileName(string inFileName)
{
    string fileOutName;
    cout << endl
         << "What would you like to name the file for storing the sorted contents of " << inFileName << "?" << endl
         << "(Do not include file extension)" << endl;
    getline(cin, fileOutName);
    while (!isStringInput(fileOutName))
    {
        cout << "Invalid file name. Please enter a maximum of 50 alpha-numeric characters." << endl;
        getline(cin, fileOutName);
    }

    return (fileOutName + ".txt");
}