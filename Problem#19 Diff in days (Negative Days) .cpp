#pragma warning(disable:4996)

#include <iostream>
#include<string>
#include<iomanip>

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

	if (Month < 1 || Month>12) {
		return 0;
	}

	static const short MonthsDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2 && IsLeapYear(Year)) ? 29 : MonthsDays[Month];

}

short ReadNumberOfYear() {

	short Year = 0;
	cout << "Please enter a year to check ? ";
	cin >> Year;
	return Year;

}

short ReadNumberOfMonth() {

	short Month = 0;
	do {
		cout << "\nPlease enter a month to check ? ";
		cin >> Month;
	} while (Month < 1 || Month>12);

	return Month;
}

short ReadNumberOfDay(short Month, short Year) {

	short Day = 0;
	short MaxMonthDays = NumberOfDaysInAMonth(Month, Year);

	do {
		cout << "\nPlease enter the number of day (1-" << MaxMonthDays << ") ? ";
		cin >> Day;
	} while (Day < 1 || Day>MaxMonthDays);

	cout << "\n\n";

	return Day;
}

stDate ReadFullDate() {

	stDate Date;

	Date.Year = ReadNumberOfYear();
	Date.Month = ReadNumberOfMonth();
	Date.Day = ReadNumberOfDay(Date.Month, Date.Year);

	return Date;
}

bool IsLastDayInMonth(stDate Date) {

	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));

}

bool IsLastMonthInYear(short Month) {

	return (Month == 12);

}

stDate IncreaseDateByOneDay(stDate Date) {

	if (IsLastDayInMonth(Date)) {

		if (IsLastMonthInYear(Date.Month)) {

			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;

		}
		else {
			Date.Month++;
			Date.Day = 1;
		}

	}
	else {

		Date.Day++;

	}
	return Date;
}

bool IsFirstDateLessThanSecondDate(stDate Date1, stDate Date2) {

	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

void SwapDates(stDate& Date1, stDate& Date2) {

	stDate Temp;

	Temp.Year = Date1.Year;
	Temp.Month = Date1.Month;
	Temp.Day = Date1.Day;

	Date1.Year = Date2.Year;
	Date1.Month = Date2.Month;
	Date1.Day = Date2.Day;

	Date2.Year = Temp.Year;
	Date2.Month = Temp.Month;
	Date2.Day = Temp.Day;

}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludedEndDay = false) {

	int Days = 0;
	short SwapFlagValue = 1;

	if (!IsFirstDateLessThanSecondDate(Date1, Date2)) {

		SwapDates(Date1, Date2);
		SwapFlagValue = -1;

	}

	while (IsFirstDateLessThanSecondDate(Date1, Date2)) {

		Days++;
		Date1 = IncreaseDateByOneDay(Date1);

	}
	
	return IncludedEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}

int main() {

	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	cout << "\nDifference Is  : " << GetDifferenceInDays(Date1, Date2) << " Day(s).";
	cout << "\nDifference (Including End Day) Is : " << GetDifferenceInDays(Date1, Date2, true) << " Day(s).";
	cout << "\n\n";

	system("pause>0");
	return 0;
}