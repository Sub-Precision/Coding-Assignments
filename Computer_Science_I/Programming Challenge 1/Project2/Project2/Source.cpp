#include <iostream>


using namespace std;
int numberCounter(long long);
long long number;
int evens = 0;
int odds = 0;
int zeroes = 0;
int numLength = 0;
int num;
int remain;

int main() {
	cout << "Enter a number: ";
	cin >> number;
	cout << endl;

	num = numberCounter(number);


	cout << "The number of even digits: " << evens << endl;
	cout << "The number of odd digits: " << odds << endl;
	cout << "The number of zeroes: " << zeroes << endl;


	return 0;
}

int numberCounter(long long number) {
	for (int i = 0; number != 0; ++i) {
		remain = (number / 2) % 0;
		if (remain == 0)
			evens = evens + 1;
		else if (num == 0)
			zeroes = zeroes + 1;
		else if (remain != 0)
			odds = odds + 1;
		number = number / 10;
		return 0;
	}
}
