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

short TotalDaysFromTheBeginningOfTheYear(short Year, short Month, short Day) {

	short TotalDays = 0;

	for (short i = 1; i <= Month - 1; i++) {

		TotalDays += NumberOfDaysInAMonth(i, Year);

	}

	TotalDays += Day;

	return TotalDays;
}

stDate ReadFullDate() {

	stDate Date;

	Date.Year = ReadNumberOfYear();
	Date.Month = ReadNumberOfMonth();
	Date.Day = ReadNumberOfDay(Date.Month, Date.Year);

	return Date;
}

bool IsFirstDateLessThanSecondDate(stDate Date1, stDate Date2) {

	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int main() {

	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();
	
	if (IsFirstDateLessThanSecondDate(Date1, Date2)) {
		cout << "\nYes ,Date1 Less Than Date2.";
	}
	else {
		cout << "\nNo ,Date1 Is Not Less Than Date2.";
	}

	system("pause>0");
	return 0;
}