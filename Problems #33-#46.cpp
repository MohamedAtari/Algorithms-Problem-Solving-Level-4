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

	stDate Date1 = ReadFullDate();

	cout << "\nDate: " << GetDate(Date1) << "\n";

	Date1 = DecreaseDateByOneDay(Date1);
	cout << "\n01-Subtracting one day is: " << GetDate(Date1);

	Date1 = DecreaseDateByXDays(Date1, 10);
	cout << "\n02-Subtracting 10 days is: " << GetDate(Date1);

	Date1 = DecreaseDateByOneWeek(Date1);
	cout << "\n03-Subtracting one week is: " << GetDate(Date1);

	Date1 = DecreaseDateByXWeeks(Date1, 10);
	cout << "\n04-Subtracting 10 weeks is: " << GetDate(Date1);

	Date1 = DecreaseDateByOneMonth(Date1);
	cout << "\n05-Subtracting one month is: " << GetDate(Date1);

	Date1 = DecreaseDateByXMonths(Date1, 5);
	cout << "\n06-Subtracting 5 months is: " << GetDate(Date1);

	Date1 = DecreaseDateByOneYear(Date1);
	cout << "\n07-Subtracting one year is: " << GetDate(Date1);

	Date1 = DecreaseDateByXYear(Date1, 10);
	cout << "\n08-Subtracting 10 Years is: " << GetDate(Date1);

	Date1 = DecreaseDateByXYearFaster(Date1, 10);
	cout << "\n09-Subtracting 10 Years (faster) is: " << GetDate(Date1);

	Date1 = DecreaseDateByOneDecade(Date1);
	cout << "\n10-Subtracting one Decade is: " << GetDate(Date1);

	Date1 = DecreaseDateByXDecades(Date1, 10);
	cout << "\n11-Subtracting 10 Decades is: " << GetDate(Date1);

	Date1 = DecreaseDateByXDecades(Date1, 10); 
	cout << "\n12-Subtracting 10 Decade (faster) is: " << GetDate(Date1);

	Date1 = DecreaseDateByOneCentury(Date1);
	cout << "\n13-Subtracting One Century is: " << GetDate(Date1);

	Date1 = DecreaseDateByOneMillennium(Date1);
	cout << "\n14-Subtracting One Millennium is: " << GetDate(Date1);

	cout << "\n\n";

	system("pause>nul");
	return 0;
}