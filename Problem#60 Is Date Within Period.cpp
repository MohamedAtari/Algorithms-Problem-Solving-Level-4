#include <iostream>
#include<string>
#include<iomanip>

using namespace std;

struct stDate {

	short Year = 0;
	short Month = 0;
	short Day = 0;

};

struct stPeriod {

	stDate StartDate;
	stDate EndDate;

};

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {

	return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}

bool IsDate1LessOrEqualThanDate2(stDate Date1, stDate Date2) {
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false) || IsDate1EqualDate2(Date1,Date2);
}

bool IsDate1AfterOrEqualDate2(stDate Date1, stDate Date2) {
	return IsDate1LessOrEqualThanDate2(Date2, Date1) || IsDate1EqualDate2(Date1, Date2);
}

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

stPeriod ReadPeriod() {

	stPeriod Period;

	cout << "Enter Start Date : \n";
	Period.StartDate = ReadFullDate();

	cout << "Enter End Date : \n";
	Period.EndDate = ReadFullDate();

	while (IsDate1LessOrEqualThanDate2(Period.EndDate, Period.StartDate)) {
		cout << "Error End Date Is Less Than Start Date !\n";
		cout << "Enter End Date : \n";
		Period.EndDate = ReadFullDate();
	}

	return Period;
}

enum enCompareDatesStatus { Before = -1, Eqauls = 0, After = 1 };

enCompareDatesStatus CompareDates(stDate Date1, stDate Date2) {

	if (IsDate1AfterOrEqualDate2(Date1, Date2))
		return enCompareDatesStatus::After;

	if (IsDate1EqualDate2(Date1, Date2))
		return enCompareDatesStatus::Eqauls;

	return enCompareDatesStatus::Before;

}

bool IsDateinPeriod(stDate Date, const stPeriod& Period) {

	return !((CompareDates(Date, Period.StartDate) == enCompareDatesStatus::Before
		    ||
		CompareDates(Date, Period.EndDate) == enCompareDatesStatus::After));

}

int main() {

	stPeriod Period;
	stDate Date;

	cout << "Enter Period :\n\n";
	Period = ReadPeriod();

	cout << "Enter Date To Check :\n\n";

	Date = ReadFullDate();

	if (IsDateinPeriod(Date, Period)) {
		cout << "Yes , The Date Within The Period.";
	}
	else {
		cout << "No , The Date Is Not Within The Period.";
	}

	system("pause>0");
	return 0;
}