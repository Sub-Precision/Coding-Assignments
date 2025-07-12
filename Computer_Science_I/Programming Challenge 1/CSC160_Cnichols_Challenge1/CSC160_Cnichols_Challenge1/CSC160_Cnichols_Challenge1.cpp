#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int SSN;
	double hours;
	double payRate;
	double totalPay;
	double SSTax;
	double FITax;
	double stateTax;
	double donation;
	double coDependants;
	double netPay;
	double overtime;

	payRate = 16.78;
	overtime = payRate * 1.5;

	cout << "Enter employee SSN (digits only, no spaces or dashes): ";
	cin >> SSN;

	cout << "Please the enter hours worked: ";
	cin >> hours;
	cout << endl;

	cout << setprecision(2) << fixed;
	totalPay = hours * payRate;
	SSTax = totalPay * 0.06;
	FITax = totalPay * 0.14;
	stateTax = totalPay * 0.05;
	donation = 10.00;
	netPay = totalPay - SSTax - FITax - stateTax - donation;

	cout << "Employee number: " << SSN << endl;
	cout << "Hours worked: " << hours << endl;
	cout << "regular pay rate: " << payRate << endl;
	cout << "gross pay: " << totalPay << endl;
	cout << "FICA tax withheld: " << SSTax << endl;
	cout << "Federal Income Tax withheld: " << FITax << endl;
	cout << "State Tax withheld: " << stateTax << endl;
	cout << "CCA Foundation Donation withheld: " << donation << endl;
	cout << "Net Pay: " << netPay << endl;

	system("pause");
	return 0;
}
