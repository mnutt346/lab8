/**************************************************************************************
** Program name: binSearch.cpp
** Author: Michael Nutt
** Date: 11/19/2019
** Description: Implementation file for the binSearch function.
**************************************************************************************/
#include "binSearch.hpp"

bool binSearch(int *targetArray, int arrayLength, int targetValue)
{
    int low = 0;
    int high = arrayLength - 1;

    while (low <= high)
    {
        int midPoint = (low + high) / 2;
        int midValue = targetArray[midPoint];

        // If the target is in the upper half of the list
        if (midValue < targetValue)
        {
            // Divide the list in two and continue with the upper half
            low = midPoint + 1;
        }
        // If the target is in the lower half of the list
        else if (midValue > targetValue)
        {
            // Divide the list in two and continue with the lower half
            high = midPoint - 1;
        }
        // If the target is neither less than or greater than the mid value, it must be equal
        else
        {
            return true;
        }
    }

    // Target not found
    return false;
}