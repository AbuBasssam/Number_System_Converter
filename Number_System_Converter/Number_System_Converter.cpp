#include "iostream"
#include"string"

using namespace std;
enum enChoiceFrom { fDicemal = 1, fBinary = 2, fOctal = 3, fHexaDicemal = 4, fExit = 5 };

enum enChoiceTo { tDicemal = 1, tBinary = 2, tOtcal = 3, tHexaDicemal = 4 };

int ReadNumberOnlyWithRange(int From, int To) {
	int Number;

	cin >> Number;
	while (cin.fail() || Number<From || Number>To) {

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one:" << endl;
		cin >> Number;
	}
	return Number;
}

string ReadString() {
	string sNumber;
	cout << "Enter your number ";
	cin >> sNumber;
	return sNumber;
}

enChoiceFrom ReadFrom() {
	int Choice = ReadNumberOnlyWithRange(1, 5);
	return (enChoiceFrom)Choice;
}

enChoiceTo ReadTo() {
	short Choice = ReadNumberOnlyWithRange(1, 4);
	return (enChoiceTo)Choice;
}

int ReadNumberOnly()
{
	int Number;
	cout << "\nEnter your Number ";
	cin >> Number;
	while (cin.fail()) {

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one:" << endl;
		cin >> Number;
	}
	return Number;
}

string ReverseWord(string Word)
{
	string word2;
	int Length = Word.length();
	for (int i = 0; i <= Length; i++) {
		word2 += Word[Length - i];
	}
	return word2;
}


bool IsBinary(int Number)
{
	int Remainder = 0;
	while (Number > 0) {

		Remainder = Number % 10;
		if (Remainder != 0 && Remainder != 1) { return false; }

		Number = Number / 10;

	}
	return true;
}

int BinaryToDicemal(int Number)
{
	while (!IsBinary(Number)) {
		cout << "\nSorry invalid Number,please enter another one ";
		cin >> Number;
	}
	int Remainder = 0, Result = 0;
	short Counter = 0;

	while (Number > 0) {

		Remainder = Number % 10;
		if (Remainder == 1) {
			Result += pow(2, Counter);
		}
		Counter++;

		Number = Number / 10;


	}

	return Result;
}


string DicemalToBinary(int Number)
{
	int Remainder = 0;
	string Result = "";


	while (Number > 0) {

		Remainder = Number % 2;

		Number = floor(Number / 2);
		Result += to_string(Remainder);


	}
	Result = ReverseWord(Result);

	return Result;

}

string DicemalToOctal(int Number)
{
	int Remainder = 0;
	string Result = "";


	while (Number > 0) {

		Remainder = Number % 8;

		Number = floor(Number / 8);
		Result += to_string(Remainder);


	}
	Result = ReverseWord((Result));
	return Result;

}


int OctalToDicemal(int Number)
{
	int Remainder = 0, Result = 0;
	short Counter = 0;
	while (Number > 0) {

		Remainder = Number % 10;
		Result += Remainder * pow(8, Counter);
		Counter++;
		Number = Number / 10;

	}
	return Result;
}


string HexaTable(int Number)
{
	string Hexa[6] = { "A","B","C","D","E","F" };
	switch (Number) {
	case 10: { return "A"; }
	case 11: { return "B"; }
	case 12: { return "C"; }
	case 13: { return "D"; }
	case 14: { return "E"; }
		   return "F";

	}

}


string DicemalToHexa(int Number)
{
	int Remainder = 0;
	string Result = "";

	while (Number > 0) {

		Remainder = Number % 16;
		if (Remainder > 9) { Result += HexaTable(Remainder); }

		else { Result += to_string(Remainder); }
		Number = floor(Number / 16);



	}

	return ReverseWord(Result);
}


bool IsLetter(char Character)
{
	for (char i = 65; i <= 90; i++) {
		if (i == Character) {
			return true;
		}
	}
	return false;
}


short CharacterConverter(char Character)
{
	switch (Character) {

	case 'A': { return 10; }

	case 'B': { return 11; }

	case 'C': { return 12; }

	case 'D': { return 13; }

	case 'E': { return 14; }

	case 'F': { return 15; }

	}
}


short CharacterNumberConverter(char Character)
{

	switch (Character) {
	case '0': { return 0; }

	case '1': { return 1; }

	case '2': { return 2; }

	case '3': { return 3; }

	case '4': { return 4; }

	case '5': { return 5; }

	case '6': { return 6; }

	case '7': { return 7; }

	case '8': { return 8; }

	case '9': { return 9; }
	}
}


int HexaToDicemal(string Number)
{
	int Result = 0;
	short Counter = 0;
	for (int i = Number.length() - 1; i >= 0; i--) {
		if (IsLetter(Number[i])) {
			Result += (CharacterConverter(Number[i]) * (pow(16, Counter)));
			Counter++;
		}
		else
		{
			Result += (CharacterNumberConverter(Number[i]) * (pow(16, Counter)));
			Counter++;

		}
	}
	return Result;
}


string BinaryToHexa(int Number)
{
	while (!IsBinary(Number)) {
		cout << "\nSorry invalid Number,please enter another one ";
		cin >> Number;
	}
	int Result = 0;
	string FinalResult;

	Result = BinaryToDicemal(Number);
	FinalResult = DicemalToHexa(Result);
	return FinalResult;
}

string HexaToBinary(string Number)
{
	int Number2 = HexaToDicemal(Number);
	string Result = DicemalToBinary(Number2);
	return Result;
}

string OctalToBinary(int Number)
{
	int Number2 = OctalToDicemal(Number);
	string Result = DicemalToBinary(Number2);
	return Result;
}


string BinaryToOctal(int Number)
{
	while (!IsBinary(Number)) {
		cout << "\nSorry invalid Number,please enter another one ";
		cin >> Number;
	}
	int Number2 = BinaryToDicemal(Number);
	string Result = DicemalToOctal(Number2);
	return Result;

}


void ChoiceFromMenu()
{

	cout << "\n\t\tChoose system to Convert from it\n";
	cout << "\n------------------------------------------------------------------\n";
	cout << "------------------------------------------------------------------\n";
	cout << "[1] : Dicemal System\n";
	cout << "[2] : Binary System\n";
	cout << "[3] : Octal System\n";
	cout << "[4] : HexaDicemal System\n";
	cout << "[5] : Exit";
	cout << "\n------------------------------------------------------------------\n";
	cout << "------------------------------------------------------------------\n";
	cout << "Enter your Choice ";

}


void ChoiceToMenu()
{
	system("cls");

	cout << "\n\n\t\tChoose system to Convert to it\n";
	cout << "\n------------------------------------------------------------------\n";
	cout << "------------------------------------------------------------------\n";
	cout << "[1] : Dicemal System\n";
	cout << "[2] : Binary System\n";
	cout << "[3] : Octal System\n";
	cout << "[4] : HexaDicemal System\n";
	cout << "\n------------------------------------------------------------------\n";
	cout << "------------------------------------------------------------------\n";
	cout << "Enter your Choice ";




}


void ReturnToChoiceMenu() {
	system("cls");
	ChoiceFromMenu();
}


void ChoiceConvertOperation(enChoiceFrom fChoice, enChoiceTo tChoice) {


	if (fChoice == enChoiceFrom::fDicemal && tChoice == enChoiceTo::tBinary)
	{
		cout << DicemalToBinary(ReadNumberOnly());
		


	}
	else if (fChoice == enChoiceFrom::fDicemal && tChoice == enChoiceTo::tOtcal)
	{
		cout << DicemalToOctal(ReadNumberOnly());
	}
	else if (fChoice == enChoiceFrom::fDicemal && tChoice == enChoiceTo::tHexaDicemal)
	{
		cout << DicemalToHexa(ReadNumberOnly());
	}
	else if (fChoice == enChoiceFrom::fBinary && tChoice == enChoiceTo::tOtcal)
	{
		cout << BinaryToOctal(ReadNumberOnly());
	}
	else if (fChoice == enChoiceFrom::fBinary && tChoice == enChoiceTo::tDicemal)
	{
		cout << BinaryToDicemal(ReadNumberOnly());
	}
	else if (fChoice == enChoiceFrom::fBinary && tChoice == enChoiceTo::tHexaDicemal)
	{
		cout << BinaryToHexa(ReadNumberOnly());
	}
	else if (fChoice == enChoiceFrom::fOctal && tChoice == enChoiceTo::tDicemal)
	{
		cout << OctalToDicemal(ReadNumberOnly());
	}
	else if (fChoice == enChoiceFrom::fOctal && tChoice == enChoiceTo::tBinary)
	{
		cout << OctalToBinary(ReadNumberOnly());
	}
	else if (fChoice == enChoiceFrom::fOctal && tChoice == enChoiceTo::tHexaDicemal)
	{
		int Number = OctalToDicemal(ReadNumberOnly());
		string Number2 = DicemalToHexa(Number);
		cout << Number2;
	}
	else if (fChoice == enChoiceFrom::fHexaDicemal && tChoice == enChoiceTo::tOtcal)
	{
		int Number = HexaToDicemal(ReadString());
		string Number2 = DicemalToOctal(Number);
		cout << Number2;

	}
	else if (fChoice == enChoiceFrom::fHexaDicemal && tChoice == enChoiceTo::tBinary)
	{

		cout << HexaToBinary(ReadString());
	}
	else
	{
		cout << HexaToDicemal(ReadString());
	}
	system("pause>0");
}



void StartProgram() {
	ChoiceFromMenu();
	enChoiceFrom Choice = ReadFrom();
	while (Choice != enChoiceFrom::fExit) {


		cout << "\n" << endl;
		ChoiceToMenu();
		enChoiceTo Choice2 = ReadTo();
		while (Choice == Choice2) {
			cout << "Sorry Wrong Choice try Another one ";
			Choice2 = ReadTo();

		}

		ChoiceConvertOperation(Choice, Choice2);
		ReturnToChoiceMenu();
		Choice = ReadFrom();
	}
}
int main()
{
	StartProgram();
	return 0;
}
