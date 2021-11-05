#include <iostream>
#include <ctime>
#include <string>
using namespace std;
const string messageForMenu = "________________________________________________________________________________________________________________________\n-1- int to string\n-2- double to string\n-3- translation of several elements of a number to string\n-4- number of recurring by arrays\n-5- number of recurring by string\n-0- EXIT";

bool isNumberNumeric();
int inputNumber();
void byKeyboard(int amount, int* array);
void showArray(int amount, int* array);
void byRandom(int amount, int* array);
int* buildArray(int& amount);
int* buildArray(int& amount);
string toString(double numberDouble, int intPartOfNumber);
string toString(int numberInt);
string toString(int numberInt, int numberOfPrintElements);
void numberOfMeetingsNumbers(int number, int* array, int amount);
string buildString(int* array, int amount);
void numberOfMeetingsNumbers(int number, string line);
void intToString();
void doubleToString();
void SeveralElementsOfNumberToString();
void numberOfRecurringByArrays();
void numberOfRecurringByString();






int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	while (true) 
	{
		cout << messageForMenu << endl << "Your choise: ";
		int toggle = inputNumber();
		if (toggle == 0)
			return 0;
		switch (toggle)
		{
		case 1:
		{
			intToString();
			break;
		}
		case 2:
		{
			doubleToString();
			break;
		}
		case 3:
		{
			SeveralElementsOfNumberToString();
			break;
		}
		case 4:
		{
			numberOfRecurringByArrays();
			break;
		}
		case 5:
		{
			numberOfRecurringByString();
			break;
		}
		default:
		{
			cout << "Incorrect input!\nTry again\n";
			break;
		}
		}
	}
	system("pause");
	return 0;
}

void numberOfRecurringByString()
{
	cout << "Enter a number: ";
	int number = inputNumber();
	int amount, counterRec;
	int* array = buildArray(amount);
	string line = buildString(array, amount);
	cout << endl << line;
	numberOfMeetingsNumbers(number, line);
}

void numberOfRecurringByArrays()
{
	cout << "Enter a number: ";
	int number = inputNumber();
	int amount, counterRec;
	int* array = buildArray(amount);
	showArray(amount, array);
	numberOfMeetingsNumbers(number, array, amount);
}

void SeveralElementsOfNumberToString()
{
	int numberInt;
	do {
		cout << "Enter a integer number: ";
		numberInt = inputNumber();
	} while (numberInt > 999999999);
	cout << "Enter a number of elements which you want to print : ";
	int numberOfPrintElements = inputNumber();
	string number = toString(numberInt, numberOfPrintElements);
	cout << number << "\n";
}

void doubleToString()
{
	cout << "Enter a double number: ";
	double numberDouble;
	cin >> numberDouble;
	int intPartOfNumber = numberDouble;
	double realItemsOfNumber = numberDouble - intPartOfNumber;
	int realPathOfNumber = realItemsOfNumber * 10000;
	string intPathString = toString(numberDouble, intPartOfNumber);
	string realPathString = toString(numberDouble, realPathOfNumber);
	string stringNumberDouble = intPathString + "." + realPathString;
	cout << stringNumberDouble << endl;
}


void intToString()
{
	int numInt;
	do {
		cout << "Enter a integer number: ";
		numInt = inputNumber();
	} while (numInt > 999999999);
	string number = toString(numInt);
	cout << number << "\n";
}

bool isNumberNumeric()
{
	if (cin.get() == '\n')
		return true;
	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
}

int inputNumber()
{
	int number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric())
		{
			return number;
		}
		else
		{
			cout << "Incorrect input!\n" << "Try again: ";
		}
	}
}

void byKeyboard(int amount, int* array)
{
	for (int i = 0; i < amount; ++i)
	{
		cout << "Введите элемент массива: ";
		array[i] = inputNumber();
	}
}

void showArray(int amount, int* array)
{
	for (int i = 0; i < amount; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void byRandom(int amount, int* array)
{
	int left_value, right_value;
	cout << "Введите начало отрезка: ";
	left_value = inputNumber();
	do {
		cout << "Введите конец отрезка: ";
		right_value = inputNumber();
		if (left_value >= right_value) cout << "Конец отрезка не может быть меньше начала или равен ему!\n";
	} while (left_value >= right_value || right_value < 0);

	for (int i = 0; i < amount; ++i)
	{
		int z = rand() % 3;
		if (z == 1)
			z = -1;
		else
			z = 1;
		array[i] = (rand() % (right_value - left_value + 1) + left_value) * z;
	}
}

int* buildArray(int& amount)
{
	int code;
	do {
		cout << "Введите количество элементов массива: ";
		amount = inputNumber();
		if (amount < 1) cout << "Размер массива не может быть отрицательным или равным нулю!\n";
		if (amount > 9999) cout << "Размер массива не может быть больше 9999!\n";
	} while (amount < 1 || amount > 9999);
	int* array = new int[amount];
	do {
		cout << "Выберите способ задания массива:\n" <<
			"-1- ввод с клавиатуры\n" <<
			"-2- задание рандомными числами на выбранном отрезке\n";
		cout << "Введите код вашего выбора: ";
		code = inputNumber();
		switch (code)
		{
		case 1: byKeyboard(amount, array); break;
		case 2: byRandom(amount, array); break;
		default: cout << "Вы можете использовать только '1' и '2'\n";
		}
	} while (code < 1 || code > 2);
	return array;
}

string toString(double numberDouble, int intPartOfNumber)
{
	int numberOfElements = 1, numberForSimbol, i = 0;
	string line;
	if (intPartOfNumber < 0)
	{
		line += "-";
		intPartOfNumber *= -1;
	}
	short oneSymbol;
	numberForSimbol = intPartOfNumber;
	int numberForLenght = intPartOfNumber;

	while ((numberForLenght /= 10) > 0)
		numberOfElements++;
	int* array = new int[numberOfElements];

	while (intPartOfNumber >= 1)
	{
		oneSymbol = intPartOfNumber % 10;
		intPartOfNumber /= 10;
		array[i] = oneSymbol;
		i++;
	}
	for (int i = numberOfElements - 1; i >= 0; --i)
	{
		line += (char)array[i] + 48;
	}

	delete[] array;
	return line;
}

string toString(int numberInt)
{
	int numberOfElements = 1, numberForSimbol, i = 0;
	string line;

	if (numberInt == 0)
	{
		line = "0";
		return line;
	}

	if (numberInt < 0)
	{
		line += "-";
		numberInt *= -1;
	}
	short oneSymbol;
	numberForSimbol = numberInt;
	int numberForLenght = numberInt;
	while ((numberForLenght /= 10) > 0)
		numberOfElements++;
	int* array = new int[numberOfElements];

	while (numberInt >= 1)
	{
		oneSymbol = numberInt % 10;
		numberInt = numberInt / 10;
		array[i] = oneSymbol;
		i++;
	}
	for (int i = numberOfElements - 1; i > -1; --i)
	{
		line += (char)array[i] + 48;
	}

	delete[] array;
	return line;
}


string toString(int numberInt, int numberOfPrintElements)
{
	int numberOfElements = 1, numberForSimbol, i = 0;
	string line = toString(numberInt);
	string lineTrimed;
	for (int i = 0; i < numberOfPrintElements; i++)
		lineTrimed += line[i];
	line = lineTrimed;
	return line;
}

void numberOfMeetingsNumbers(int number, int* array, int amount)
{
	int counterRec = 0;
	for (int i = 0; i < amount - 1; i++)
	{
		if (array[i] == number)
		{
			counterRec++;
		}
	}
	if (counterRec == 0)
	{
		cout << "There is no " << number << "\n\n";
	}
	else
		cout << "Number of recurring " << number << " = " << counterRec << endl << "\n";
	delete[] array;
}

string buildString(int* array, int amount)
{
	string line;
	for (int i = 0; i < amount; i++)
	{
		line += toString(array[i]);
		line += " ";
	}
	return line;
}

void numberOfMeetingsNumbers(int number, string line)
{
	int counterOfRecElements = 0;
	string numberStr = toString(number), buildingNumber;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] != ' ')
			buildingNumber += line[i];
		else
		{
			if (buildingNumber == numberStr)
				counterOfRecElements++;
			buildingNumber = "";
		}
	}
	if (counterOfRecElements == 0)
	{
		cout << "\nThere is no " << numberStr << "\n\n";
	}
	else
		cout << endl << "Number of recurring " << numberStr << " = " << counterOfRecElements << endl;
}

