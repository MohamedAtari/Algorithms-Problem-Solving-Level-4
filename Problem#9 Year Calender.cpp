#include <iostream>
#include<string>
#include<iomanip>

using namespace std;

bool IsLeapYear(short Year) {

	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));

}

short NumberOfDaysInAMonth(short Year, short Month) {

	if (Month < 1 || Month>12) {
		return 0;
	}

	short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : MonthsDays[Month - 1];

}

short GetDayNameIndex(short Year, short Month, short Day) {

	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + 12 * a - 2;

	return	 (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string GetMonthName(short MonthIndex) {

	string MonthsNames[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	return MonthsNames[MonthIndex - 1];
}

short ReadNumberOfYear() {

	short Year = 0;
	cout << "Please enter a year to check : ";
	cin >> Year;
	return Year;

}

void PrintMonthCalender(short Year, short Month) {

	short DaysInAMonth = NumberOfDaysInAMonth(Year,Month);
	short FirstDayNameIndex = GetDayNameIndex(Year,Month,1);

	printf("\n\n\n---------------%s---------------\n\n", GetMonthName(Month).c_str());
	printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	short i;
	for (i = 0; i < FirstDayNameIndex; i++) {

		printf("     ");

	}

	for (short Day = 1; Day <= DaysInAMonth; Day++) {

		printf("%3d  ", Day);

		if (++i == 7) {

			cout << '\n';
			i = 0;
		}

	}

	printf("\n\n---------------------------------");

}

void PrintYearCalender(short Year) {

	printf("\n\n---------------------------------\n\n");
	printf("\tClaender - %d", Year);
	printf("\n\n---------------------------------\n");

	for (short Month = 1; Month <= 12; Month++) {

		PrintMonthCalender(Year, Month);

	}

}

int main() {

	PrintYearCalender(ReadNumberOfYear());

	system("pause>0");
	return 0;
}