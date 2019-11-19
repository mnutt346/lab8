/**************************************************************************************
** Program name: fileReader.hpp
** Author: Michael Nutt
** Date: 11/19/2019
** Description: Header file for the file-reading functions.
**************************************************************************************/
#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <string>

int getFileLength(std::string);

void fileReader(std::string, int *);

#endif