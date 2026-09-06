#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> BelowTwenty = {
	"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
	"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
	"Seventeen", "Eighteen", "Nineteen"
};

const vector<string> Tens = {
	"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

const vector<string> Thousands = {
	"", "Thousand", "Million", "Billion", "Trillion"
};

long long ReadNumber() {

	long long Number = 0;
	cout << "Please Enter A Number : ";
	cin >> Number;
	return Number;

}

string ConvertChunkUnder1000(short Number) {

	string Result = "";

	if (Number >= 1000)
		return"";

	if (Number >= 100) {

		Result += BelowTwenty[Number / 100] + " Hundred";
		Number %= 100;

		if (Number > 0) {
			Result += " ";
		}
	}

	if (Number >= 20) {

		Result += Tens[Number / 10];

		if (Number % 10 > 0) {
			Result += " " + BelowTwenty[Number % 10];
		}

	}else{

		Result += BelowTwenty[Number];

	}
	return Result;
}

string NumberToTextUsingLoop(long long Number) {

	if (Number == 0) return "Zero";
	if (Number < 0)return "Negative " + NumberToTextUsingLoop(-Number);

	string Result = "";
	int Chunk = 0;
	short ChunkIndex = 0;

	while (Number > 0) {

		Chunk = Number % 1000;

		if (Chunk != 0) {

			string ChunkText = ConvertChunkUnder1000(Chunk);

			if (ChunkIndex<(short)Thousands.size() && !Thousands[ChunkIndex].empty()) {
				ChunkText += " " + Thousands[ChunkIndex];
			}

			if (Result.empty()) {
				Result = ChunkText;
			}
			else {
				Result = ChunkText + " " + Result;
			}

		}

		Number /= 1000;
		ChunkIndex++;

	}
	return Result;
}

string NumberToTextUsingRecursion(long long Number) {
	
	if (Number <= 0)
		return "";

	if (Number >= 1 && Number <= 19) {

		string arr[] = {"","One","Two","Three","Four","Five","Six","Seven",
			"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen"
		,"Sixteen","Seventeen","Eighteen","Nineteen" };

		return arr[Number] + " ";
	}

	if (Number >= 20 && Number <= 99) {

		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

		return arr[Number / 10] + " " + NumberToTextUsingRecursion(Number % 10);
	}

	if (Number >= 100 && Number <= 999) {

		return NumberToTextUsingRecursion(Number / 100) + "Hundred " + NumberToTextUsingRecursion(Number % 100) ;

	}

	if (Number >= 1000 && Number <= 999999) {

		return NumberToTextUsingRecursion(Number / 1000) + "Thousand " + NumberToTextUsingRecursion(Number % 1000);

	}

	if (Number >= 1000000 && Number <= 999999999) {

		return NumberToTextUsingRecursion(Number / 1000000) + "Million " + NumberToTextUsingRecursion(Number % 1000000);

	}

	if (Number >= 1000000000 && Number <= 999999999999) {

		return NumberToTextUsingRecursion(Number / 1000000000) + "Billion " + NumberToTextUsingRecursion(Number % 1000000000);

	}
	
	if (Number >= 1000000000000) {

		return NumberToTextUsingRecursion(Number / 1000000000000) + "Trillion " + NumberToTextUsingRecursion(Number % 1000000000000);

	}

	return "";
}

int main() {

	long long Number = ReadNumber();

	cout << NumberToTextUsingRecursion(Number);

	return 0;
}