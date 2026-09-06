#include <iostream>
#include<string>

using namespace std;

bool IsLeapYear(short Year) {

	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));

}

short NumberOfDaysInAMonth(short Month,short Year) {

	if (Month < 1 || Month>12)
		return 0;

	if (Month == 2) {

		return IsLeapYear(Year) ? 29 : 28;

	}
	
	short arr31Days[7] = {1,3,5,7,8,10,12};
	
	for (int i = 1; i <= 12; i++) {

		if (arr31Days[i - 1] == Month)
			return 31;

	}

	return 30;
}

short NumberOfHoursInAMonth(short Month,short Year) {

	return NumberOfDaysInAMonth(Month, Year) * 24;

}

int NumberOfMinutesInAMonth(short Month,short Year) {

	return NumberOfHoursInAMonth(Month, Year) * 60;

}

int NumberOfSecondsInAMonth(short Month , short Year) {

	return NumberOfMinutesInAMonth(Month, Year) * 60;

}

void PrintMonthDetails(short Month, short Year) {

	cout << "\n\nNumber Of Days In Month [" << Month << "] Is : " << NumberOfDaysInAMonth(Month, Year) ;
	cout << "\nNumber Of Hours In Month [" << Month << "] Is : " << NumberOfHoursInAMonth(Month, Year);
	cout << "\nNumber Of Minutes In Month [" << Month << "] Is : " << NumberOfMinutesInAMonth(Month, Year);
	cout << "\nNumber Of Seconds In Month [" << Month << "] Is : " << NumberOfSecondsInAMonth(Month, Year);


}

short ReadNumberOfMonth() {

	short Month = 0;
	cout << "\n\nPlease enter a month to check : ";
	cin >> Month;
	return Month;

}

short ReadYear() {

	short Year = 0;
	cout << "Please enter a year to check : ";
	cin >> Year;
	return Year;

}

int main() {

	short Year = ReadYear();
	short Month = ReadNumberOfMonth();

	PrintMonthDetails(Month, Year);

	system("pause>0");
	return 0;
}
