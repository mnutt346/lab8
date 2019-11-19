/**************************************************************************************
** Program name: quickSort.hpp
** Author: Michael Nutt
** Date: 11/19/2019
** Description: Header file for the quick sort functions.
** Algorithm found at: https://www.geeksforgeeks.org/quick-sort/
**************************************************************************************/
#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

void quickSort(int *&, int, int);

int pivot(int *&, int, int);

void swap(int *, int *);

#endif