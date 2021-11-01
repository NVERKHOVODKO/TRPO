#include <iostream>
#include <ctime>
#include <string>
using namespace std;

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

string toString(int numberInt)
{
	int numberOfElements = 1, numberForSimbol, i = 0;
	string line;
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
		numberOfElements++;
		i++;
	}
	for (int i = numberOfElements - 1; i > -1; --i)
	{
		int item = array[i];
		switch (item)
		{
		case 0:
			line += "0";
			break;
		case 1:
			line += "1";
			break;
		case 2:
			line += "2";
			break;
		case 3:
			line += "3";
			break;
		case 4:
			line += "4";
			break;
		case 5:
			line += "5";
			break;
		case 6:
			line += "6";
			break;
		case 7:
			line += "7";
			break;
		case 8:
			line += "8";
			break;
		case 9:
			line += "9";
			break;
		}
	}
	cout << line << "\n";
	delete[] array;
	return line;
}


void convertToString(double numberDouble)
{
	string numberString;
	numberString = to_string(numberDouble);
	cout << numberString << "\n";
}

void convertToString(int numberInt)
{
	string numberString;
	numberString = toString(numberInt);
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

void convertToString(int numberInt, int numOfItems)
{
	string numberString;
	numberString = to_string(numberInt);
	for (int i = 0; i < numOfItems; i++)
	{
		cout << numberString[i];
	}
	cout << endl;
}

void numberOfMeetingsNumbers(int number, string lineOfNumbers)
{

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

void buildString()
{
	int size;
	do {
		cout << "Enter a size of string(1-10000): ";
		size = inputNumber();
	} while (size < 1 || size > 10000);
	string line;
	int item;
	for (int i = 0; i < size; ++i)
	{
		item = rand() % 9;
		switch (item)
		{
		case 0:
			line += "0";
			break;
		case 1:
			line += "1";
			break;
		case 2:
			line += "2";
			break;
		case 3:
			line += "3";
			break;
		case 4:
			line += "4";
			break;
		case 5:
			line += "5";
			break;
		case 6:
			line += "6";
			break;
		case 7:
			line += "7";
			break;
		case 8:
			line += "8";
			break;
		case 9:
			line += "9";
			break;
			line += " ";
		}
	}
	cout << line << endl;

}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int toggle, numOfItems, numberInt;
	double numberDouble;
	while (true)
	{
		do {
			cout << "-1- Convert int to string\n-2- Convert double to string\n-3- Convert multiple characters int to string\n-4- Count recurring items by string\n-5- Count recurring items by array\n-0- EXIT\nYour choise: ";
			toggle = inputNumber();
		} while (toggle > 5 || toggle < 0);
		cout << "\n";
		if (toggle == 0)
			return 0;
		else
		{
			switch (toggle)
			{
			case 1:
				cout << "Enter a number: ";
				numberInt = inputNumber();
				convertToString(numberInt);
				break;
			case 2:
				cout << "Enter a number: ";
				cin >> numberDouble;
				convertToString(numberDouble);
				break;
			case 3:
				cout << "Enter a number: ";
				numberInt = inputNumber();
				cout << "Enter a number of elements: ";
				numOfItems = inputNumber();
				convertToString(numberInt, numOfItems);
				break;
			case 4:
				buildString();
				break;
			case 5:
				cout << "Enter a number: ";
				int number = inputNumber();
				int amount, counterRec;
				int* array = buildArray(amount);
				numberOfMeetingsNumbers(number, array, amount);
				break;

			}
		}
	}
	system("pause");
	return 0;
}