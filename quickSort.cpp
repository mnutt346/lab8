/**************************************************************************************
** Program name: quickSort.cpp
** Author: Michael Nutt
** Date: 11/19/2019
** Description: Implementation file for the quick sort functions.
** Algorithm found at: https://www.geeksforgeeks.org/quick-sort/
**************************************************************************************/
#include "quickSort.hpp"

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int pivot(int *&targetArray, int low, int high)
{
    int pivotValue = targetArray[low];
    int index = low;
    int upperBound = high + 1;

    do
    {
        do
        {
            index++;
        } while (targetArray[index] < pivotValue && index <= upperBound);

        do
        {
            upperBound--;
        } while (pivotValue < targetArray[upperBound]);

        if (index < upperBound)
        {
            swap(targetArray[index], targetArray[upperBound]);
        }

    } while (index < upperBound);

    targetArray[low] = targetArray[upperBound];
    targetArray[upperBound] = pivotValue;

    return upperBound;
}

void quickSort(int *&targetArray, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = pivot(targetArray, low, high);

        quickSort(targetArray, low, pivotIndex - 1);
        quickSort(targetArray, pivotIndex + 1, high);
    }
}