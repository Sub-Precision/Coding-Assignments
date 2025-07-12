# CSCI 2421 - 001
* Programming Homework 2
* Cade Nichols
* Cade.nichols@UCDenver.edu

# Project Files
* Algorithms.h - has various functions
* ArrayList.h - has all functions pertaining to arrays
* Exceptions.h - has all exeption handling functions
* LinkedList.h - has all function pertaining to linked lists
* Makefile - g++ command to compile project
* nichols_Cade_HW2.cpp - replaced Main.cpp file and has implementation for all functions in header files
* Node.h - has all node functions
* Queue.h - contains all queue functions
* README - this
* Stack.h - has all stack functions

# Compilation
The project can be compiled be issuing the 'make' command on a linux terminal. Upon successful 
compilation, an executable named 'nichols_Cade_HW2.exe' will be created in the current directory

# Running
Issue './nichols)Cade_HW2.exe' on the command line to run the program

# Sample Output
--------------Linked List--------------------------- 
1. Operation: PushFront(-11, 2, 1) 
LinkedList: |1|<-->|2|<-->|-11|<-->NULL 
2. Operation: PushBack(10, 4, 5) 
LinkedList: |1|<-->|2|<-->|-11|<-->|10|<-->|4|<-->|5|<-->NULL 
3. Operation: PopFront() 
LinkedList: |2|<-->|-11|<-->|10|<-->|4|<-->|5|<-->NULL 
4. Operation: PopBack() 
LinkedList: |2|<-->|-11|<-->|10|<-->|4|<-->NULL 
5. Operation: Find(10) 
 
--------------Array List (Vector)--------------------------- 
1. Operation: PushBack(-11, 2, 1, 5, 8) 
Vector: [-11,2,1,5,8,] 
2. Operation: PopBack() 
Vector: [-11,2,1,5,] 
2. Operation: Reverse() 
Vector: [5,1,2,-11,] 
3. Operation: BubbleSort() 
Vector: [-11,1,2,5,] 
 
--------------Stacks--------------------------- 
1. Operation: PushBack(4, 3, 1, -3, 8) 
Stack: (4,3,1,-3,8,) 
2. Operation: Pop() 
Removing 8 
Stack: (4,3,1,-3,) 
 
--------------Deque--------------------------- 
1. Operation: Push(10, 3, 2) 
Deque:|2|<-->|3|<-->|10|<-->NULL 
Front: 2 Rear: 10 
2. Operation: Inject(-3) 
Deque:|2|<-->|3|<-->|10|<-->|-3|<-->NULL 
Front: 2 Rear: -3 
3. Operation: Eject 
Deque:|2|<-->|3|<-->|10|<-->NULL 
Front: 2 Rear: 10 
4. Operation: Pop 
Deque:|3|<-->|10|<-->NULL 
Front: 3 Rear: 10

# Errors
No errors should occer