#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct stDate {
	short Year = 0;
	short Month = 0;
	short Day = 0;
};

string ReadDateString(string Message) {

	string DateInString;

	cout << Message;
	getline(cin >> ws, DateInString);

	return DateInString;
}

vector<string>SplitString(string S1, string Delim = "#//#") {

	vector<string>vString;
	string sWord = "";
	short pos = 0;

	while ((pos = S1.find(Delim)) != std::string::npos) {

		sWord = S1.substr(0, pos);

		if (sWord != "") {
			vString.push_back(sWord);
		}

		S1.erase(0, pos + Delim.length());

	}

	if (S1 != "") {
		vString.push_back(S1);
	}
	return vString;
}

bool IsLeapYear(short Year) {
	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInAMonth(short Month, short Year) {
	if (Month < 1 || Month > 12) {
		return 0;
	}

	static const short MonthsDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (Month == 2 && IsLeapYear(Year)) ? 29 : MonthsDays[Month];
}

bool IsValidDate(stDate Date) {

	return (Date.Month >= 1 && Date.Month <= 12) &&
		(Date.Day >= 1 && Date.Day <= NumberOfDaysInAMonth(Date.Month, Date.Year));

}

stDate StringToDate(string StringDate, bool& IsValid) {

	stDate Date;
	vector<string>vDate = SplitString(StringDate, "/");
	IsValid = false;

	if (vDate.size() != 3) {
		return Date;
	}

	try {

		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		if (IsValidDate(Date)) {
			IsValid = true;
		}

	}
	catch (...) {

		IsValid = false;

	}

	return Date;
}

string DateToString(stDate Date) {

	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);

}

void PrintDate(stDate Date) {

	cout << "\n\nDay   : " << Date.Day;
	cout << "\nMonth : " << Date.Month;
	cout << "\nYear  : " << Date.Year;

}

int main() {

	stDate Date;
	string StringDate = ReadDateString("\nPlease enter a date dd/mm/yyyy ? ");
	bool IsValid;

	Date = StringToDate(StringDate, IsValid);

	if (IsValid) {
		PrintDate(Date);
		cout << "\n\nYou Entered : " << DateToString(Date) << endl;
	}
	else {
		cout << "\nInvalid Date format or values!\n";
	}

	system("pause>0");
	return 0;
}