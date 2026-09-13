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

stDate IncreaseDateByXDays(stDate Date, int DaysToIncerease) {

	for (int Day = 1; Day <= DaysToIncerease; Day++) {
		Date = IncreaseDateByOneDay(Date);
	}
	
	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date) {

	return IncreaseDateByXDays(Date, 7);

}

stDate IncreaseDateByXWeeks(stDate Date, short WeeksToIncrease) {

	for (short Week = 1; Week <= WeeksToIncrease; Week++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date) {

	if (Date.Month != 12) {
		++Date.Month;
	}
	else {
		Date.Month = 1;
		++Date.Year;
	}

	if (Date.Day >28 ) {

		short Days = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > Days) {
			Date.Day = Days;
		}

	}

	return Date;
}

stDate IncreaseDateByXMonths(stDate Date, short MonthsToIncrease) {

	for (short Month= 1; Month <= MonthsToIncrease; Month++) {

		Date = IncreaseDateByOneMonth(Date);

	}

	return Date;
}

stDate IncreaseDateByOneYear(stDate Date) {

	++Date.Year;

	if (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) {
		Date.Day = 28;
	}

	return Date;
}

stDate IncreaseDateByXYears(stDate Date, short YearsToIncrease) {

	for (short Year = 1; Year <= YearsToIncrease; Year++) {

		Date = IncreaseDateByOneYear(Date);

	}

	return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, short YearsToIncrease) {

	Date.Year += YearsToIncrease;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) {

	Date.Year += 10;
	return Date;
}

stDate IncreaseDateByXDecade(stDate Date, short DecadesToIncrease) {

	for (short Decade = 1; Decade <= DecadesToIncrease; Decade++) {
		Date = IncreaseDateByOneDecade(Date);
	}

	return Date;
}

stDate IncreaseDateByXDecadeFaster(stDate Date, short DecadesToIncrease) {

	Date.Year += DecadesToIncrease * 10;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date) {

	Date.Year += 100;
	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date) {

	Date.Year += 1000;
	return Date;
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

string GetDate(const stDate& Date) {

	return to_string(Date.Day)+"/"+to_string(Date.Month)+"/"+to_string(Date.Year);

} 

int main() {

	stDate Date = ReadFullDate();

	cout << "Date After :";

	Date = IncreaseDateByOneDay(Date);
	cout << "\n\n01-Adding One Day Is : " << GetDate(Date);

	Date = IncreaseDateByXDays(Date, 10);
	cout << "\n02-Adding 10 Days Is : " << GetDate(Date);

	Date = IncreaseDateByOneWeek(Date);
	cout << "\n03-Adding One Week Is : " << GetDate(Date);

	Date = IncreaseDateByXWeeks(Date, 10);
	cout << "\n04-Adding 10 Weeks Is : " << GetDate(Date);

	Date = IncreaseDateByOneMonth(Date);
	cout << "\n05-Adding One Month Is : " << GetDate(Date);

	Date = IncreaseDateByXMonths(Date, 5);
	cout << "\n06-Adding 5 Months Is : " << GetDate(Date);

	Date = IncreaseDateByOneYear(Date);
	cout << "\n07-Adding One Year Is : " << GetDate(Date);

	Date = IncreaseDateByXYears(Date,10);
	cout << "\n08-Adding 10 Years Is : " << GetDate(Date);

	Date = IncreaseDateByXYearsFaster(Date,10);
	cout << "\n09-Adding 10 Year (Faster) Is : " << GetDate(Date);

	Date = IncreaseDateByOneDecade(Date);
	cout << "\n10-Adding One Decade Is : " << GetDate(Date);

	Date = IncreaseDateByXDecade(Date,10);
	cout << "\n11-Adding 10 Decades Is : " << GetDate(Date);

	Date = IncreaseDateByXDecadeFaster(Date,10);
	cout << "\n12-Adding 10 Decades (Faster) Is : " << GetDate(Date);

	Date = IncreaseDateByOneCentury(Date);
	cout << "\n13-Adding One Century Is : " << GetDate(Date);

	Date = IncreaseDateByOneMillennium(Date);
	cout << "\n14-Adding One Millennium Is : " << GetDate(Date);

	system("pause>0");
	return 0;
}