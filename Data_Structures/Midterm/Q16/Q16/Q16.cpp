// Q16.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program was created by Cade Nichols for question 16 of the midterm exam

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void reverse(vector<int> arr)
{
	stack<int> stack;
	int size = arr.size();

	for (int i = 0; i < arr.size(); i++)
	{
		stack.push(arr[i]);
	}
	arr.clear();

	for (int j = 0; j < size; ++j)
	{
		arr[j] = stack.top();
		stack.pop();
	}

}

