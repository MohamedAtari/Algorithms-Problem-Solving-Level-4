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

bool IsLastDayInMonth(stDate Date) {

	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));

}

bool IsLastMonthInYear(short Month) {

	return (Month == 12);

}

bool IsWeekEnd(stDate Date) {

	short DayOrederIndex = DayOrderInWeek(Date);
	return (DayOrederIndex == 5 || DayOrederIndex == 6);
}

bool IsBusinessDay(stDate Date) {
	return !IsWeekEnd(Date);
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

stDate ReadFullDate() {

	stDate Date;

	Date.Year = ReadNumberOfYear();
	Date.Month = ReadNumberOfMonth();
	Date.Day = ReadNumberOfDay(Date.Month, Date.Year);

	return Date;
}

stDate CalculateVecationReturnDate(stDate Date,short VacationDays) {

	short WeekEndsDays = 0;

	for (short i = 1; i <= VacationDays + WeekEndsDays; i++) {

		if (IsWeekEnd(Date)) {
			WeekEndsDays++;
		}

		Date = IncreaseDateByOneDay(Date);

	}

	while (IsWeekEnd(Date)) {
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

stDate CalculateVecationReturnDateFaster(stDate Date, short VacationDays) {

	while (VacationDays > 0) {

		if (IsBusinessDay(Date)) {
			VacationDays--;
		}

		Date = IncreaseDateByOneDay(Date);

	}

	while (IsWeekEnd(Date)) {
		Date = IncreaseDateByOneDay(Date);
	}

}

stDate CalculateVecationReturnDateAnthorWay(stDate Date, short VacationDays) {

	for (short i = 1 ; i <= VacationDays; i++) {

		while (IsWeekEnd(Date)) {
			Date = IncreaseDateByOneDay(Date);
		}

		Date = IncreaseDateByOneDay(Date);
	}

}

int main() {

	stDate VacationSatarts;
	stDate VacationReturnDate;
	short VacationDays = 0;

	VacationSatarts = ReadFullDate();

	cout << "Please enter vacation days? ";
	cin >> VacationDays;

	VacationReturnDate = CalculateVecationReturnDate(VacationSatarts,VacationDays);

	cout << "Return Date : " << GetDayNameByIndex(DayOrderInWeek(VacationReturnDate)) << " , ";
	cout << VacationReturnDate.Day << "/" << VacationReturnDate.Month << "/" << VacationReturnDate.Year;

	system("pause>0");
	return 0;
}