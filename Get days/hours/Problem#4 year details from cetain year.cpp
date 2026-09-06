#include <iostream>
#include<string>

using namespace std;

bool IsLeapYear(short Year) {

	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));

}

short NumberOfDaysInAYear(short Year) {
	return (IsLeapYear(Year)) ? 366 : 365;
}

short NumberOfHoursInAYear(short Year) {
	return NumberOfDaysInAYear(Year) * 24;
}

int NumberOfMinutesInAYear(short Year) {
	return NumberOfHoursInAYear(Year) * 60;
}

int NumberOfSecondsInAYear(short Year) {
	return NumberOfMinutesInAYear(Year) * 60;
}

void PrintYearDetails(short Year) {

	cout << "\nNumber Of Days In Year [" << Year << "] Is " << NumberOfDaysInAYear(Year);
	cout << "\nNumber Of Hours In Year [" << Year << "] Is " << NumberOfHoursInAYear(Year);
	cout << "\nNumber Of Minutes In Year [" << Year << "] Is " << NumberOfMinutesInAYear(Year);
	cout << "\nNumber Of Seconds In Year [" << Year << "] Is " << NumberOfSecondsInAYear(Year);

}

short ReadYear() {

	short Year = 0;
	cout << "Please enter a year to check : ";
	cin >> Year;
	return Year;

}

int main() {

	short Year = ReadYear();

	PrintYearDetails(Year);
	
	system("pause>0");
	return 0;
}
