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

	static const short MonthsDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2 && IsLeapYear(Year)) ? 29 : MonthsDays[Month];

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

stDate DateAddDays(stDate Date, short Days) {

	short CurrentMonthDays = 0;

	while (true) {

		CurrentMonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Days > CurrentMonthDays) {

			Days -= CurrentMonthDays;

			if (Date.Month == 12) {
				Date.Year++;
				Date.Month = 0;
			}

			Date.Month++;

		}
		else {

			Date.Day = Days + Date.Day;
			break;

		}

	}

	return Date;
}

stDate ReadFullDate() {

	stDate Date;
	
	Date.Year = ReadNumberOfYear();
	Date.Month = ReadNumberOfMonth();
	Date.Day = ReadNumberOfDay(Date.Month,Date.Year);

	return Date;
}

short ReadDaysToAdd() {

	short Days = 0;
	cout << "\n\nHow Many Days To Add : ";
	cin >> Days;
	return Days;

}

int main(){

	stDate Date = ReadFullDate();
	short DaysToAdd = ReadDaysToAdd();

	Date = DateAddDays(Date,DaysToAdd);
	
	cout << "\n\nDate After Added [" << DaysToAdd << "] Days Is : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}