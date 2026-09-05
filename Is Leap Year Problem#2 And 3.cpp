#include <iostream>
#include<string>

using namespace std;

short ReadYear() {

	short Year = 0;
	cout << "Please enter the year to chick if it's a leap year or not : ";
	cin >> Year;
	return Year;

}

bool IsLeapYear(short Year) {

	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));

}

int main() {

	short Year = ReadYear();

	if (IsLeapYear(Year)) {
		cout << "\nYes Year["<<Year<<"] Is A Leap Year\n";
	}
	else {
		cout << "\nNo Year[" << Year << "] Is Not A Leap Year\n";
	}

	system("pause>0");
	return 0;
}
