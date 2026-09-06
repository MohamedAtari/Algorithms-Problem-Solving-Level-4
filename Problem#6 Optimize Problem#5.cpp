#include <iostream>
#include<string>

using namespace std;

bool IsLeapYear(short Year) {

	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));

}

short NumberOfDaysInAMonth(short Month, short Year) {

	if (Month < 1 || Month>12) {
		return 0;
	}
	
	short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : MonthsDays[Month - 1];
}

short NumberOfHoursInAMonth(short Month, short Year) {

	return NumberOfDaysInAMonth(Month, Year) * 24;

}

int NumberOfMinutesInAMonth(short Month, short Year) {

	return NumberOfHoursInAMonth(Month, Year) * 60;

}

int NumberOfSecondsInAMonth(short Month, short Year) {

	return NumberOfMinutesInAMonth(Month, Year) * 60;

}

void PrintMonthDetails(short Month, short Year) {

	cout << "\n\nNumber Of Days In Month [" << Month << "] Is : " << NumberOfDaysInAMonth(Month, Year);
	cout << "\nNumber Of Hours In Month [" << Month << "] Is : " << NumberOfHoursInAMonth(Month, Year);
	cout << "\nNumber Of Minutes In Month [" << Month << "] Is : " << NumberOfMinutesInAMonth(Month, Year);
	cout << "\nNumber Of Seconds In Month [" << Month << "] Is : " << NumberOfSecondsInAMonth(Month, Year);


}

short ReadNumberOfMonth() {

	short Month = 0;
	cout << "\n\nPlease enter a month to check : ";
	cin >> Month;

	return Month;
}

short ReadYear() {

	short Year = 0;
	cout << "Please enter a year to check : ";
	cin >> Year;
	return Year;

}

int main() {

	short Year = ReadYear();
	short Month = ReadNumberOfMonth();

	PrintMonthDetails(Month, Year);

	system("pause>0");
	return 0;
}
