#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct stDate {
	short Year = 0;
	short Month = 0;
	short Day = 0;
};

bool IsLeapYear(short Year) {
	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInAMonth(short Month, short Year) {
	if (Month < 1 || Month > 12) {
		return 0;
	}

	static const short MonthsDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (Month == 2 && IsLeapYear(Year)) ? 29 : MonthsDays[Month];
}

short ReadNumberOfYear() {
	short Year = 0;
	cout << "Please enter a year to check ? ";
	cin >> Year;
	cout << "\n";
	return Year;
}

short ReadNumberOfMonth() {
	short Month = 0;
	do {
		cout << "Please enter a month to check ? ";
		cin >> Month;
	} while (Month < 1 || Month > 12);

	return Month;
}

short ReadNumberOfDay() {
	short Day;
	cout << "Please enter the number of day ? ";
	cin >> Day;
	return Day;
}

stDate ReadFullDate() {
	stDate Date;
	Date.Day = ReadNumberOfDay();
	Date.Month = ReadNumberOfMonth();
	Date.Year = ReadNumberOfYear();
	return Date;
}

bool IsValidDate(stDate Date) {

	if (Date.Month < 1 || Date.Month>12)
		return false;
	
	if (Date.Day < 1 || Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year))
		return false;


	return true;
}

int main() {
	
	stDate Date = ReadFullDate();

	if (IsValidDate(Date)) {
		cout << "Yes , It's A Valid Date\n";
	}
	else {
		cout << "No , It's Not A Valid Date\n";
	}

	system("pause>0");
	return 0;
}