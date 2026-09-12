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

	++Date.Month;

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

	return Date;
}

stDate IncreaseDateByXYears(stDate Date, short YearsToIncrease) {

	for (short Year = 1; Year <= YearsToIncrease; Year++) {

		Date = IncreaseDateByOneDay(Date);

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

	for (short Decade = 0; Decade <= DecadesToIncrease; Decade++) {
		Date = IncreaseDateByOneDay(Date);
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



}

int main() {

	

	system("pause>0");
	return 0;
}