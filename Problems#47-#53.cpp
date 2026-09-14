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

stDate GetCurrentDate() {

	stDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}

short DayOrderInWeek(short Year, short Month, short Day) {

	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + 12 * a - 2;

	return	 (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOrderInWeek(const stDate Date) {

	return DayOrderInWeek(Date.Year, Date.Month, Date.Day);
   
}

string GetDayNameByIndex(short DayOrderIndex) {

	static const string DaysName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return DaysName[DayOrderIndex];
}

short TotalDaysFromTheBeginningOfTheYear(short Year, short Month, short Day) {

	short TotalDays = 0;

	for (short i = 1; i <= Month - 1; i++) {

		TotalDays += NumberOfDaysInAMonth(i, Year);

	}

	TotalDays += Day;

	return TotalDays;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Date2Sum = 0;

	for (short i = Date1.Year; i < Date2.Year; i++) {
		Date2Sum += TotalDaysFromTheBeginningOfTheYear(i, 12, 31);
	}

	Date2Sum += TotalDaysFromTheBeginningOfTheYear(Date2.Year, Date2.Month, Date2.Day);

	int Diff = Date2Sum - TotalDaysFromTheBeginningOfTheYear(Date1.Year, Date1.Month, Date1.Day);

	return IncludeEndDay ? ++Diff : Diff;
}

bool IsEndOfWeek(stDate Date) {
	return DayOrderInWeek(Date) == 6;
}

bool IsWeekEnd(stDate Date) {

	short DayOrederIndex = DayOrderInWeek(Date);
	return (DayOrederIndex == 5 || DayOrederIndex == 6);
}

bool IsBusinessDay(stDate Date) {
	return !IsWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(stDate Date) {
	 
	return 6 - DayOrderInWeek(Date);

}

short DaysUntilTheEndOfMonth(stDate Date) {
	 
	stDate EndMonthDate;

	EndMonthDate.Year = Date.Year;
	EndMonthDate.Month = Date.Month;
	EndMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);

	return GetDifferenceInDays(Date,EndMonthDate);
}

short DaysUntilTheEndOfYear(stDate Date) {

	stDate EndYearDate;

	EndYearDate.Year = Date.Year;
	EndYearDate.Month = 12;
	EndYearDate.Day = 31;

	return GetDifferenceInDays(Date,EndYearDate);
}

int main() {

	stDate Date = GetCurrentDate();

	cout << "Today is " << GetDayNameByIndex(DayOrderInWeek(Date));
	cout << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	cout << "\n\nIs It End Of Week?";

	if (IsEndOfWeek(Date)) {
		cout << "\nYes it is end of week.";
	}
	else {
		cout << "\nNo it is not end of week.";
	}

	cout << "\n\nIs It Weekend?";

	if (IsWeekEnd(Date)) {
		cout << "\nYes it is a week end.";
	}
	else {
		cout << "\nNo it is not a week end.";
	}

	cout << "\n\nIs It Business Day?";

	if (IsBusinessDay(Date)) {
		cout << "\nYes it is a business day.";
	}
	else {
		cout << "\nNo it is not a business day.";
	}

	cout << "\n\nDays until end of week : " << DaysUntilTheEndOfWeek(Date) << " Day(s).";
	cout << "\nDays until end of month : " << DaysUntilTheEndOfMonth(Date) << " Day(s).";
	cout << "\nDays until end of year : " << DaysUntilTheEndOfYear(Date) << " Day(s).\n";

	system("pause>nul");
	return 0;
}