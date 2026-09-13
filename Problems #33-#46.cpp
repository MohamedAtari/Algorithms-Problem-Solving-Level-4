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

stDate DecreaseDateByOneDay(stDate Date) {

	if (Date.Day == 1) {
		
		if (Date.Month != 1) {

			--Date.Month;
			Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);

		}
		else {

			--Date.Year;
			Date.Month = 12;
			Date.Day = 31;

		}

	}
	else {
		--Date.Day;
	}

	return Date;
}

stDate DecreaseDateByXDays(stDate Date,int Days) {

	for (int Day = 1; Day <= Days; Day++) {
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date) {

	return DecreaseDateByXDays(Date,7);

}

stDate DecreaseDateByXWeeks(stDate Date,short Weeks) {

	return DecreaseDateByXDays(Date, Weeks * 7);

}

stDate DecreaseDateByOneMonth(stDate Date) {

	if (Date.Month == 1) {

		--Date.Year;
		Date.Month = 12;

	}
	else {
		--Date.Month;
	}

	if (Date.Day > 28) {

		short TotalDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > TotalDays) {
			Date.Day = TotalDays;
		}

	}

	return Date;
}

stDate DecreaseDateByXMonths(stDate Date, short Months) {

	for (short Month = 1; Month <= Months; Month++) {
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate DecreaseDateByOneYear(stDate Date) {

	--Date.Year;

	if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
		Date.Day = 28;
	}

	return Date;

}

stDate DecreaseDateByXYear(stDate Date,short Years) {

	for (short Year = 1; Year <= Years; Year++) {
		Date = DecreaseDateByOneYear(Date);
	}

	if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
		Date.Day = 28;
	}

	return Date;
}

stDate DecreaseDateByXYearFaster(stDate Date, short Years) {

	Date.Year -= Years;

	if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
		Date.Day = 28;
	}

	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date) {

	Date.Year -= 10;

	if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
		Date.Day = 28;
	}

	return Date;
}

stDate DecreaseDateByXDecades(stDate Date,short Decades) {

	Date.Year -= (Decades*10) ;

	if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
		Date.Day = 28;
	}

	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date) {

	Date.Year -= 100;

	if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
		Date.Day = 28;
	}

	return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date) {

	Date.Year -= 1000;

	if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
		Date.Day = 28;
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

string GetDate(const stDate& Date) {

	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);

}

int main() {

	stDate Date = ReadFullDate();

	cout << "\nDate: " << GetDate(Date) << "\n\n";

	cout << "01-Subtracting one day is: " << GetDate(DecreaseDateByOneDay(Date)) << "\n";
	cout << "02-Subtracting 10 days is: " << GetDate(DecreaseDateByXDays(Date, 10)) << "\n";
	cout << "03-Subtracting one week is: " << GetDate(DecreaseDateByOneWeek(Date)) << "\n";
	cout << "04-Subtracting 10 weeks is: " << GetDate(DecreaseDateByXWeeks(Date, 10)) << "\n";
	cout << "05-Subtracting one month is: " << GetDate(DecreaseDateByOneMonth(Date)) << "\n";
	cout << "06-Subtracting 5 months is: " << GetDate(DecreaseDateByXMonths(Date, 5)) << "\n";
	cout << "07-Subtracting one year is: " << GetDate(DecreaseDateByOneYear(Date)) << "\n";
	cout << "08-Subtracting 10 years is: " << GetDate(DecreaseDateByXYear(Date, 10)) << "\n";
	cout << "09-Subtracting one decade is: " << GetDate(DecreaseDateByOneDecade(Date)) << "\n";
	cout << "10-Subtracting 10 decades is: " << GetDate(DecreaseDateByXDecades(Date, 10)) << "\n";
	cout << "11-Subtracting one century is: " << GetDate(DecreaseDateByOneCentury(Date)) << "\n";
	cout << "12-Subtracting one millennium is: " << GetDate(DecreaseDateByOneMillennium(Date)) << "\n";

	system("pause>0");
	return 0;
}