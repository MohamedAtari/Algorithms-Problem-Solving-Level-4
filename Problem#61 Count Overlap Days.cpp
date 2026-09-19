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

struct stPeriod {
	stDate StartDate;
	stDate EndDate;
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

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
	return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}

bool IsDate1LessThanDate2(stDate Date1, stDate Date2) {
	return (Date1.Year < Date2.Year) ? true :
		((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
			(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
	return IsDate1LessThanDate2(Date2, Date1);
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
	} while (Month < 1 || Month > 12);

	return Month;
}

short ReadNumberOfDay(short Month, short Year) {
	short Day = 0;
	short MaxMonthDays = NumberOfDaysInAMonth(Month, Year);

	do {
		cout << "Please enter the number of day (1-" << MaxMonthDays << ") ? ";
		cin >> Day;
	} while (Day < 1 || Day > MaxMonthDays);

	cout << "\n";
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

	cout << "Enter Start Date:\n";
	Period.StartDate = ReadFullDate();

	cout << "Enter End Date:\n";
	Period.EndDate = ReadFullDate();

	while (IsDate1LessThanDate2(Period.EndDate, Period.StartDate)) {
		cout << "\nError: End Date Is Less Than Start Date!\n";
		cout << "Enter End Date Again:\n";
		Period.EndDate = ReadFullDate();
	}

	return Period;
}

bool IsLastDayInMonth(stDate Date) {
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {
	return (Month == 12);
}

void SwapDates(stDate& Date1, stDate& Date2) {
	stDate Temp = Date1;
	Date1 = Date2;
	Date2 = Temp;
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

enum enCompareDatesStatus { Before = -1, Equals = 0, After = 1 };

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludedEndDay = false) {
	int Days = 0;
	short SwapFlagValue = 1;

	if (!IsDate1LessThanDate2(Date1, Date2)) {
		SwapDates(Date1, Date2);
		SwapFlagValue = -1;
	}

	while (IsDate1LessThanDate2(Date1, Date2)) {
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludedEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}

int PeriodLengthInDays(const stPeriod& Period, bool IncludeEndDate = false) {
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}

enCompareDatesStatus CompareDates(stDate Date1, stDate Date2) {
	if (IsDate1LessThanDate2(Date1, Date2))
		return enCompareDatesStatus::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enCompareDatesStatus::Equals;

	return enCompareDatesStatus::After;
}

bool IsOverlapPeriods(const stPeriod& Period1, const stPeriod& Period2) {
	if (CompareDates(Period1.EndDate, Period2.StartDate) == enCompareDatesStatus::Before ||
		CompareDates(Period1.StartDate, Period2.EndDate) == enCompareDatesStatus::After) {
		return false;
	}
	return true;
}

bool IsDateinPeriod(stDate Date, const stPeriod& Period) {
	return !(CompareDates(Date, Period.StartDate) == enCompareDatesStatus::Before ||
		CompareDates(Date, Period.EndDate) == enCompareDatesStatus::After);
}

int CountOverLapDays(stPeriod Period1,stPeriod Period2) {
	if (!IsOverlapPeriods(Period1, Period2))
		return 0;

	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);
	int OverLapDays = 0;

	
	if (Period1Length < Period2Length) {

		while (IsDate1LessThanDate2(Period1.StartDate, Period1.EndDate) ||IsDate1EqualDate2(Period1.StartDate,Period1.EndDate)) {

			if (IsDateinPeriod(Period1.StartDate, Period2)) {
				OverLapDays++;
			}
			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}
	}
	else {

		while (IsDate1LessThanDate2(Period2.StartDate, Period2.EndDate)||IsDate1EqualDate2(Period2.StartDate, Period2.EndDate)) {

			if (IsDateinPeriod(Period2.StartDate, Period1)) {
				OverLapDays++;
			}
			Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
		}
	}

	return OverLapDays;
}

int CountOverLapDaysFaster(const stPeriod& Period1, const stPeriod& Period2, bool IncludeEndDate = false) {

	if (!IsOverlapPeriods(Period1, Period2)) {
		return 0;
	}

	stDate OverlapStart = IsDate1AfterDate2(Period1.StartDate, Period2.StartDate) ? Period1.StartDate : Period2.StartDate;

	stDate OverlapEnd = IsDate1LessThanDate2(Period1.EndDate, Period2.EndDate) ? Period1.EndDate : Period2.EndDate;

	return GetDifferenceInDays(OverlapStart, OverlapEnd, IncludeEndDate);
}

int main() {
	cout << "--- Period 1 ---\n";
	stPeriod Period1 = ReadPeriod();

	cout << "\n--- Period 2 ---\n";
	stPeriod Period2 = ReadPeriod();

	cout << "\nOverLap Days Count Is : " << CountOverLapDaysFaster(Period1, Period2,true) << "\n";

	system("pause>0");
	return 0;
}