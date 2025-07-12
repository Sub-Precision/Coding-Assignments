# CSCI 2421 - 001
* Programming Homework 1
* Cade Nichols
* Cade.nichols@UCDenver.edu

# Project Files
* Rectangle.h - Contains definition of rectangle class
* Rectangle.cpp - contains implementation of rectangle class
* Comparator.h - implementation of comparator class for comparing rectangles by area and perimeter
* hw1.cpp - implements the driver for the project. This file also includes a findmax template 
implementation to find the max area and max perimeter rectangle from a list of rectangles
* Makefile - g++ command to compile project

# Compilation
The project can be compiled be issuing the 'make' command on a linux terminal. Upon successful 
compilation, an executable named 'hw1.exe' will be created in the current directory

# Running
Issue './hw1.exe' on the command line to run the program

# Sample Output
How many rectangles?(Max 10): 3
Rectangle 1 Length: 2
Rectangle 1 Width: 4
Rectangle 2 Length: 3
Rectangle 2 Width: 6
Rectangle 3 Length: 4
Rectangle 3 Width: 8

Your list of rectangles are:
Rectangle 1
Length of rectangle 1: 2
Width of rectangle 1: 4
Rectangle 2
Length of rectangle 2: 3
Width of rectangle 2: 6
Rectangle 3
Length of rectangle 3: 4
Width of rectangle 3: 8
The largest rectangle by perimeter is:
The largest rectangle by area is:

# Errors
Errors will only occur if user inputs more than 10 rectangles 
as 10 has been the hard coded cap handled by the program