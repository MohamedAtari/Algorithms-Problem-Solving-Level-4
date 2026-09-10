#include <iostream>
#include<string>
#include<iomanip>

using namespace std;

bool IsLeapYear(short Year) {

	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));

}

short NumberOfDaysInAMonth(short Month, short Year) {

	if (Month < 1 || Month>12) {
		return 0;
	}

	static const short MonthsDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2 && IsLeapYear(Year)) ? 29 : MonthsDays[Month];

}

struct stDate {

	short Year = 0;
	short Month = 0;
	short Day = 0;

};

short ReadNumberOfYear() {

	short Year = 0;
	cout << "Please enter a year to check : ";
	cin >> Year;
	return Year;

}

short ReadNumberOfMonth() {

	short Month = 0;
	do {
		cout << "\nPlease enter a month to check : ";
		cin >> Month;
	} while (Month < 1 || Month>12);

	return Month;
}

short ReadNumberOfDay(short Month, short Year) {

	short Day = 0;
	short MaxMonthDays = NumberOfDaysInAMonth(Month, Year);

	do {
		cout << "\nPlease enter the number of day (1-" << MaxMonthDays << ") :";
		cin >> Day;
	} while (Day < 1 || Day>MaxMonthDays);

	cout << "\n\n";

	return Day;
}

stDate ReadFullDate() {

	stDate Date;

	Date.Year = ReadNumberOfYear();
	Date.Month = ReadNumberOfMonth();
	Date.Day = ReadNumberOfDay(Date.Month,Date.Year);

	return Date;
}

bool IsLastDayInMonth(stDate Date) {

	return (Date.Day == NumberOfDaysInAMonth(Date.Month,Date.Year));

}

bool IsLastMonthInYear(short Month) {

	return (Month == 12);

}

int main() {

	stDate Date = ReadFullDate();

	if (IsLastDayInMonth(Date))
		cout << "\n\nYes , day is last day in month.";
	else
		cout << "\n\nNo , day is not last day in month.";

	if (IsLastMonthInYear(Date.Month))
		cout << "\n\nYes , month is last month in year.";
	else
		cout << "\n\nNo , month is not last month in year.";

	system("pause>0");
	return 0;
}