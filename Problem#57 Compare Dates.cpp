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
		cout << "Please enter a month to check ? ";
		cin >> Month;
	} while (Month < 1 || Month>12);

	return Month;
}

short ReadNumberOfDay(short Month, short Year) {

	short Day = 0;
	short MaxMonthDays = NumberOfDaysInAMonth(Month, Year);

	do {
		cout << "Please enter the number of day (1-" << MaxMonthDays << ") ? ";
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

enum enCompareDatesStatus { Before = -1, Eqauls = 0, After = 1 };

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {

	return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}

bool IsDate1LessThanDate2(stDate Date1, stDate Date2) {
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDat1AfterDate2(stDate Date1, stDate Date2) {
	return (!IsDate1LessThanDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum enCompareDatesStatus {Before = -1,Eqauls = 0 , After = 1};

enCompareDatesStatus CompareDates(stDate Date1, stDate Date2) {

	return (IsDate1LessThanDate2(Date1, Date2) ? enCompareDatesStatus::Before : ((IsDate1EqualDate2(Date1, Date2)) ? enCompareDatesStatus::Eqauls : enCompareDatesStatus::After));

	if (IsDat1AfterDate2(Date1, Date2))
		return enCompareDatesStatus::After;

	if (IsDate1EqualDate2(Date1, Date2))
		return enCompareDatesStatus::Eqauls;

	return enCompareDatesStatus::Before;

}

int main() {

	cout << "Enter Date1 : \n";
	stDate Date1 = ReadFullDate();
	cout << "Enter Date2 : \n";
	stDate Date2 = ReadFullDate();

	cout << "Compare Result : " << CompareDates(Date1, Date2) << endl;

	system("pause>0");
	return 0;
}