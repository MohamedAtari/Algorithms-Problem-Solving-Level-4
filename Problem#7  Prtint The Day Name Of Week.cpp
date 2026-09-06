#include <iostream>
#include<string>

using namespace std;

bool IsLeapYear(short Year) {

	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));

}

short NumberOfDaysInAMonth(short Month, short Year){

	if (Month < 1 || Month>12) {
		return 0;
	}

	short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : MonthsDays[Month];

}

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

short ReadNumberOfDay(short Month , short Year) {

	short Day = 0;
	short MaxMonthDays = NumberOfDaysInAMonth(Month, Year);

	do {
		cout << "\n\nPlease enter the number of day (1-" << MaxMonthDays << ") :";
		cin >> Day;
	} while (Day < 1 || Day>MaxMonthDays);

	return Day;
}

short GetDayIndex(short Year, short Month, short Day) {

	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + 12 * a - 2;

	return	 (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string GetDayName(short DayIndex) {

	string DaysNames[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	return DaysNames[DayIndex];
}

int main() {

	short Year = ReadNumberOfYear();
	short Month = ReadNumberOfMonth();
	short Day = ReadNumberOfDay(Month,Year);
	short DayIndex = GetDayIndex(Year, Month, Day);


	cout << "\n\nDate      : " << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayIndex;
	cout << "\nDay Name  : " << GetDayName(DayIndex);

	system("pause>0");
	return 0;
}
