/**************************************************************************************
** Program name: quickSort.cpp
** Author: Michael Nutt
** Date: 11/19/2019
** Description: Implementation file for the quick sort functions.
** Algorithm found at: https://www.geeksforgeeks.org/quick-sort/
**************************************************************************************/
#include "quickSort.hpp"

/* Summary: Swaps the given values
 * Param: int &num1 -> reference to a given number
 * Param: int &num2 -> reference to a given number
 * Return: N/A
 */
void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

/* Summary: Determines a pivot point and moves all values less than the 
 * pivot to the left and all values greater to the right.
 * Param: int *&targetArray -> reference to the array of integers to be sorted
 * Param: int low -> start of the section being pivoted
 * Param: int high -> end of the section being pivoted
 * Return: integer value representing the current index of the pivot point
 */
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

/* Summary: Sorts the values of the given array in ascending order
 * Param: int *&targetArray -> array of integers to be sorted
 * Param: int low -> starting index
 * Param: int high -> ending index
 * Return: N/A
 */
void quickSort(int *&targetArray, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = pivot(targetArray, low, high);

        quickSort(targetArray, low, pivotIndex - 1);
        quickSort(targetArray, pivotIndex + 1, high);
    }
}