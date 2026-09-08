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

	short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2 && IsLeapYear(Year)) ? 29 : MonthsDays[Month - 1];

}

short ReadNumberOfYear() {

	short Year = 0;
	cout << "Please enter a year to check : ";
	cin >> Year;
	return Year;

}

short ReadNumberOfMonth() {

	short Month = 0;
	do {
		cout << "\n\nPlease enter a month to check : ";
		cin >> Month;
	} while (Month < 1 || Month>12);

	return Month;
}

short ReadNumberOfDay(short Month, short Year) {

	short Day = 0;
	short MaxMonthDays = NumberOfDaysInAMonth(Month, Year);

	do {
		cout << "\n\nPlease enter the number of day (1-" << MaxMonthDays << ") :";
		cin >> Day;
	} while (Day < 1 || Day>MaxMonthDays);

	return Day;
}

short TotalDaysFromTheBeginningOfTheYear(short Year,short Month,short Day) {

	short TotalDays = 0;

	for (short i = 1; i <= Month - 1; i++) {

		TotalDays += NumberOfDaysInAMonth(Month, Year);

	}

	TotalDays += Day;

	return TotalDays;
}

int main() {

	short Year = ReadNumberOfYear();
	short Month = ReadNumberOfMonth();
	short Day = ReadNumberOfDay(Month, Year);

	cout << "\nNumber Of Days Of Th Beginning Of The Year : " << TotalDaysFromTheBeginningOfTheYear(Year, Month, Day) << endl;;

	system("pause>0");
	return 0;
}