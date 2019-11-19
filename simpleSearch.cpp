/**************************************************************************************
** Program name: simpleSearch.cpp
** Author: Michael Nutt
** Date: 11/19/2019
** Description: Implementation file for the simpleSearch function.
**************************************************************************************/
#include "simpleSearch.hpp"

bool simpleSearch(int *targetArray, int arrayLength, int targetValue)
{
    // Iterate through the array, checking each value against the target value
    for (int i = 0; i < arrayLength; i++)
    {
        // If the target is found:
        if (targetArray[i] == targetValue)
        {
            return true;
        }
    }

    // If the entire array has been searched and the target is not found:
    return false;
}