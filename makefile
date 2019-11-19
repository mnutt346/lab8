###
### @file - lab8_makefile
### @author - Michael Nutt <nuttm@oregonstate.edu>
### @description - makefile for Lab 8 - Searching and Sorting

#
# Searching and Sorting
#

CXX = g++

CFLAGS = -std=c++11

.PHONY: clean

main: main.o menu.o inputValidation.o driver.o simpleSearch.o quickSort.o fileWriter.o fileReader.o filePrinter.o binSearch.o
	$(CXX) $(CFLAGS) -g main.o menu.o inputValidation.o driver.o simpleSearch.o quickSort.o fileWriter.o fileReader.o filePrinter.o binSearch.o -o searchAndSort

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

menu.o: menu.cpp menu.hpp
	$(CXX) $(CFLAGS) -c menu.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	$(CXX) $(CFLAGS) -c inputValidation.cpp

driver.o: driver.cpp driver.hpp
	$(CXX) $(CFLAGS) -c driver.cpp

simpleSearch.o: simpleSearch.cpp simpleSearch.hpp
	$(CXX) $(CFLAGS) -c simpleSearch.cpp

quickSort.o: quickSort.cpp quickSort.hpp
	$(CXX) $(CFLAGS) -c quickSort.cpp

fileWriter.o: fileWriter.cpp fileWriter.hpp
	$(CXX) $(CFLAGS) -c fileWriter.cpp

fileReader.o: fileReader.cpp fileReader.hpp
	$(CXX) $(CFLAGS) -c fileReader.cpp

filePrinter.o: filePrinter.cpp filePrinter.hpp
	$(CXX) $(CFLAGS) -c filePrinter.cpp

binSearch.o: binSearch.cpp binSearch.hpp
	$(CXX) $(CFLAGS) -c binSearch.cpp

clean: 
	rm *.o searchAndSort