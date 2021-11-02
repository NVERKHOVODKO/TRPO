﻿#include <iostream>
#include <ctime>
#include <string>
using namespace std;

const string messageForMenu = "-1- int to string\n-2- double to string\n-3- translation of several elements of a number to string\n-4- number of rec by arrays\n-5- number of rec by string\n-0- EXIT \n Your choise: ";


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
	for (int i = 0; i < amount; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
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
		cout << "Number of " << number << " = " << counterRec << endl << "\n";
	delete[] array;
}


string buildString(int* array, int amount)
{
	string line;
	for (int i = 0; i < amount; i++)
	{
		if (array[i] == 0)
			line += "0";
		line += toString(array[i]);
		line += " ";
	}
	return line;
}

//void numberOfMeetingsNumbers(int number, string line)
//{
//	int countOfNumbers = 0;
//	string numberStr = toString(number);
//	for (int i = 0; i < line.size(); i++)
//	{
//		string stringForNumCount;
//		while (line[i] != ' ')
//		{
//			stringForNumCount += line[i];
//		}
//		if (stringForNumCount == numberStr)
//			countOfNumbers++;
//	}
//	cout << endl << countOfNumbers;
//}


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int code, numOfItems, numberInt;
	double numberDouble;
	int toggle = -1;
	while (true) {
		cout << messageForMenu;
		toggle = inputNumber();
		cout << "\n";
		if (toggle == 0)
			return 0;
		switch (toggle) 
		{
		case 1:
		{
			do {
				cout << "Enter a number: ";
				numberInt = inputNumber();
			} while (numberInt > 999999999);
			string number = toString(numberInt);
			cout << number << "\n";
			break;
		}
		case 2:
		{
			cout << "Enter a number: ";
			cin >> numberDouble;
			int intPartOfNumber = numberDouble;
			double realItemsOfNumber = numberDouble - intPartOfNumber;
			int realPathOfNumber = realItemsOfNumber * 10000;
			string intPathString = toString(numberDouble, intPartOfNumber);
			string realPathString = toString(numberDouble, realPathOfNumber);
			string stringNumberDouble = intPathString + "." + realPathString;
			cout << stringNumberDouble << endl;
			break;
		}
		case 3:
		{
			do {
				cout << "Enter a number: ";
				numberInt = inputNumber();
			} while (numberInt > 999999999);
			cout << "Enter a number of elements: ";
			int numberOfPrintElements = inputNumber();
			string number = toString(numberInt, numberOfPrintElements);
			cout << number << "\n";
			break;
		}
		case 4:
		{
			cout << "Enter a number: ";
			int number = inputNumber();
			int amount, counterRec;
			int* array = buildArray(amount);
			numberOfMeetingsNumbers(number, array, amount);
			break;
		}
		case 5:
			/*cout << "Enter a number: ";
			int number = inputNumber();
			int amount, counterRec;
			int* array = buildArray(amount);
			string line = buildString(array, amount);
			cout << endl << line;
			numberOfMeetingsNumbers(number, line);*/
			break;
		default:
			cout << "Вы можете использовать только 0-5! Попробуйте снова\n";
			break;
		}
		
	}
	system("pause");
	return 0;
}






//int main()
//{
//	srand(time(NULL));
//	setlocale(LC_ALL, "rus");
//	int code, numOfItems, numberInt;
//	double numberDouble;


	////////int to string
	/*do {
		cout << "Enter a number: ";
		numberInt = inputNumber();
	} while (numberInt > 999999999);
	string number = toString(numberInt);
	cout << number << "\n";*/


	///////// double to string
	/*cout << "Enter a number: ";
	cin >> numberDouble;
	int intPartOfNumber = numberDouble;
	double realItemsOfNumber = numberDouble - intPartOfNumber;
	int realPathOfNumber = realItemsOfNumber * 10000;
	string intPathString = toString(numberDouble, intPartOfNumber);
	string realPathString = toString(numberDouble, realPathOfNumber);
	string stringNumberDouble = intPathString + "." + realPathString;
	cout << stringNumberDouble << endl;*/


	/////////translation of several elements of a number to string
	/*do {
		cout << "Enter a number: ";
		numberInt = inputNumber();
	} while (numberInt > 999999999);
	cout << "Enter a number of elements: ";
	int numberOfPrintElements = inputNumber();
	string number = toString(numberInt, numberOfPrintElements);
	cout << number << "\n";*/


	/////////number of rec by arrays
	/*cout << "Enter a number: ";
	int number = inputNumber();
	int amount, counterRec;
	int* array = buildArray(amount);
	numberOfMeetingsNumbers(number, array, amount);*/

	/////////number of rec by string
	/*cout << "Enter a number: ";
	int number = inputNumber();
	int amount, counterRec;
	int* array = buildArray(amount);
	string line = buildString(array, amount);
	cout << endl << line;
	numberOfMeetingsNumbers(number, line);






	system("pause");
	return 0;
}*/
