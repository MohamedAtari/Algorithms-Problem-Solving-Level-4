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

short ReadNumberOfYear() {
	short Year = 0;
	cout << "Please enter a year to check ? ";
	cin >> Year;
	cout << "\n";
	return Year;
}

short ReadNumberOfMonth() {
	short Month = 0;
	do {
		cout << "Please enter a month to check ? ";
		cin >> Month;
	} while (Month < 1 || Month > 12);

	return Month;
}

short ReadNumberOfDay() {
	short Day;
	cout << "Please enter the number of day ? ";
	cin >> Day;
	return Day;
}

stDate ReadFullDate() {
	stDate Date;
	Date.Day = ReadNumberOfDay();
	Date.Month = ReadNumberOfMonth();
	Date.Year = ReadNumberOfYear();
	return Date;
}

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

string ReplaceWordInString(string S1, string StringToReplace, string ReplaceTo) {

	short pos = S1.find(StringToReplace);

	while (pos != string::npos) {

		S1 = S1.replace(pos, StringToReplace.length(),ReplaceTo);

		pos = S1.find(StringToReplace);
	}

	return S1;
}

string FormateDate(stDate Date, string FormatType = "dd/mm/yyyy") {

	string FormattedDateString = "";

	FormattedDateString = ReplaceWordInString(FormatType, "dd", to_string(Date.Day));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

	return FormattedDateString;
}

int main() {

	string StringDate = ReadDateString("\nPlease enter a date dd/mm/yyyy ? ");
	bool IsValid = false;
	

	stDate Date = StringToDate(StringDate,IsValid);

	cout << '\n';

	cout << FormateDate(Date)<<"\n";

	cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
	cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "Day:dd,Month:mm,Year:yyyy") << "\n";

	system("pause>0");
	return 0;
}