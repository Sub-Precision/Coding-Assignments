#include <cstring>
#include <iostream>

using namespace std;
char* arrayAllocator(int);

int main()
{
	// Declaring variables
	char string[99]; 
	// I dont know how to allocate an array with unknown size without explicitly 
	// asking the user how big the c-string is. That's what you did when 
	// explaining dynamic arrays was ask the user how big the array is in advance
	// So i haven't seen any way to do this without explicitly asking for
	// the size, so i will just hard code it at 99 and hope it is good enough.
	int size;
	char *pointer = nullptr;
	char temp;

	// Asking user for C-string
	cout << "Enter a string: ";
	cin >> string;

	// Getting length of C-string
	size = strlen(string);
	// Allocating array
	pointer = arrayAllocator(size);

	// Fill the array with character
	for (int i = 0; i < size; ++i)
	{
		pointer[i] = string[i];
	}

	// Rearranging letters
	for (int i = 0; i < (size / 2) + 1; i++)
	{
		
		temp = pointer[i];
		pointer[i] = pointer[size - i];
		pointer[size - i] = temp;
	}
	

	cout << "The string you entered: " << string << endl;
	cout << "Your string reversed: ";
	for (int i = 1; i < size + 1; ++i)
	{
		cout << pointer[i];
	}
	cout << endl;

	// Deallocate the array
	delete pointer;
	pointer = nullptr;

	system("pause");
	return 0;
}

char* arrayAllocator(int num)
{
	// Creating pointer for dynamic array
	char* arrPtr = nullptr;

	// Allocate space for the array
	arrPtr = new char[num + 1];

	// Return the address of the allocated memory
	return arrPtr;
}
