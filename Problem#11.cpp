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

	static const short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2 && IsLeapYear(Year)) ? 29 : MonthsDays[Month - 1];

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

short TotalDaysFromTheBeginningOfTheYear(short Year, short Month, short Day) {

	short TotalDays = 0;

	for (short i = 1; i <= Month - 1; i++) {

		TotalDays += NumberOfDaysInAMonth(i, Year);

	}

	TotalDays += Day;

	return TotalDays;
}

stDate GetDateFromDaysOrderInYear(short DaysOrderInYear, short Year) {

	stDate Date;
	short RemainingDays = DaysOrderInYear;
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = 1;

	while (true) {

		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

		if (RemainingDays > MonthDays) {

			RemainingDays -= MonthDays;
			Date.Month++;

		}
		else {

			Date.Day = RemainingDays;
			break;

		}

	}

		return Date;
}

int main() {

	short Year = ReadNumberOfYear();
	short Month = ReadNumberOfMonth();
	short Day = ReadNumberOfDay(Month, Year);
	short DaysOrderInYear = TotalDaysFromTheBeginningOfTheYear(Year, Month, Day);

	cout << "\nNumber Of Days Of Th Beginning Of The Year : " << DaysOrderInYear << endl;;

	stDate Date = GetDateFromDaysOrderInYear(DaysOrderInYear, Year);

	cout << "Date for [" << DaysOrderInYear << "] is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}