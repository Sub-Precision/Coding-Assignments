#include<iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

//Declaring Variables and functions
string p;
string converted;
int length;
int counter;
int numInput;
int isPalindromic(string);
int isPalindromic(string [], int);
int isPalindromic(int [], int);
int makePalindromic(string);
int makeInt(string);
int valInput(string);

int main()
{
    //Getting input from user
    cout << "Please enter a word, sentence or number: " << endl;
    cin >> p;

    //Evaluating Input
    length = p.length();
    
    //Checking if userInput is a palindrome
    if (isPalindromic(p) == 1)
    {
        cout << "Palindromic string." << endl;
    }
    else 
    {
        cout << "Not a palindromic string. A generated one: ";
        makePalindromic(p);
    }

    //Validating if string contains only numbers
    if (valInput(p) == 0)
    {
        //Checking if userInput is a palindrome, but this time, with numbers
        if (isPalindromic(p) == 1)
        {
            cout << "Palindromic string." << endl;
        }
        else
        {
            cout << "Not a palindromic number sequence. A generated one: ";
            makePalindromic(p);
        }
    }
    else
    {
        cout << "Not a palindromic number sequence. Generation of such sequence is not possible.";
    }
    makeInt(p);

    return 0;
}

//Overloaded functions
int isPalindromic(string x)
{
    //counter for verifying palindrome...ness
    counter = 0;

    //for loop to increment a counter every time a successful match is found
    for (int i = 0; i < length; i++)
    {
        if (x[i] == x[length - 1 - i])
            counter++;
    }
    if (counter == length)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isPalindromic(string phrase[], int x)
{
    //counter for palindromeness
    counter = 0;

    //increment loop
    for (int i = 0; i < x; i++)
    {
        if (phrase[i] == phrase[x - 1 - i])
        {
            counter++;
        }
    }
    if (counter == length)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isPalindromic(int nums[], int x)
{
    //counter for palindromeness
    counter = 0;

    //increment loop
    for (int i = 0; i < x; i++)
    {
        if (nums[i] == nums[x - 1 - i])
        {
            counter++;
        }
    }
    if (counter == length)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int makePalindromic(string x)
{
    converted = x;
    for (int i = length - 2; i >= 0; i--)
    {
        converted.push_back(x[i]);
    }
    cout << converted << endl;
    return 0;
}

int makeInt(string x)
{
    stringstream numInput(x);
    numInput >> counter;
    return counter;
}

int valInput(string x)
{
    for (int i = 0; i < length; i++)
    {
        if (!(isdigit(x[i])))
        {
            return 1;
        }

    }
    return 0;
}