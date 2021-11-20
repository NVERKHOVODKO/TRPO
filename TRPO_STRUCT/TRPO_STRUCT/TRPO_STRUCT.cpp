#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
const string SURNAME1 = "Verkhovodko";
const string SURNAME2 = "Makey";
const string SURNAME3 = "Grib";
const string SURNAME4 = "Meshennaya";
const string SURNAME5 = "Kabariha";
const string SURNAME6 = "Herrington";
const string SURNAME7 = "Loiko";
const string SURNAME8 = "Makarey";
const string NAME1 = "Tania";
const string NAME2 = "Nikita";
const string NAME3 = "Billy";
const string NAME4 = "Victor";
const string NAME5 = "lisa";
const string NAME6 = "Oleg";
const string NAME7 = "Egor";
const string NAME8 = "Tania";
const string PATRONOMIC1 = "Viacheslavovich ";
const string PATRONOMIC2 = "Alexandrovich";
const string PATRONOMIC3 = "Andreevna";
const string PATRONOMIC4 = "Pavlovich";
const string PATRONOMIC5 = "Grigorievich";
const string MENU = "======================MENU======================\n-1- Create a new list\n-2- Create new by random\n-3- Edit data\n-4- View data\n-5- Search most popular name\n-6- Search for middle age\n-7- Sort by average mark\n-0- EXIT";

struct Data
{
	int dayOfBirth;
	int mounthOfBirth;
	int yearOfBirth;

};

struct Students
{
	string name;
	string secondname;
	string patronymic;
	Data Empl;
	int groupNumber;
	int math;
	int physics;
	int informatics;
	int chemistry;
	double averageMark;
	int age;
};

bool isNumberNumeric();
int inputNumber();
void createDataRandom(Students* array, int amountOfStudents);
void createData(Students* array, int amountOfStudents);
string mostPopularName(Students* array, int amountOfStudents);
void showData(Students* array, int amountOfStudents);
void editData(Students* array, int amountOfStudents);
void sortByAverageMark(Students* array, int amountOfStudents);
void gettime(int year, int month);
int AgeOfStudent(Students* array, int amountOfStudents);
double averageAge(Students* array, int amountOfStudents);

int main()
{
	Students array[100];
	int choise, amountOfStudents;
	bool checkExistenceOfList = false;
	srand(time(0));
	do {
		cout << MENU << endl;
		do {
			choise = inputNumber();
		} while (choise > 7 || choise < 0);
		if (checkExistenceOfList == false && choise != 0)
		{
			if (choise != 1 && choise != 2)
			{
				cout << "You have not created a list!\n";
				do {
					cout << "Try again: ";
					choise = inputNumber();
				} while (choise != 1 && choise != 0);
			}
		}
		switch (choise)
		{
		case 1:
		{
			cout << "===================CREATE NEW===================\n";
			cout << "Enter a number(1-100) of students: ";
			do {
				amountOfStudents = inputNumber();
			} while (amountOfStudents > 100 || amountOfStudents < 1);
			checkExistenceOfList = true;
			createData(array, amountOfStudents);
			break;
		}
		case 2:
		{
			cout << "================CREATE NEW RANDOM================\n";
			cout << "Enter a number(1-100) of students: ";
			do {
				amountOfStudents = inputNumber();
				if (amountOfStudents > 100 || amountOfStudents < 1)
					cout << "Error! Try again: ";
			} while (amountOfStudents > 100 || amountOfStudents < 1);
			checkExistenceOfList = true;
			createDataRandom(array, amountOfStudents);
			break;
		}
		case 3:
		{
			cout << "======================EDIT======================\n";
			editData(array, amountOfStudents);
			break;
		}
		case 4:
		{
			cout << "======================VIEW======================\n";
			showData(array, amountOfStudents);
			break;
		}
		case 5:
		{
			cout << "===============MOST POPULAR NAME================\n";
			string name = mostPopularName(array, amountOfStudents);
			cout << "Most popular name in the list is " << name << endl;
			break;
		}
		case 6:
		{
			cout << "==================AVERAGE AGE===================\n";
			double averageAgeOfStudents = averageAge(array, amountOfStudents);
			cout << "Average age of students: " << averageAgeOfStudents << endl;
			break;
		}
		case 7:
		{
			cout << "======================SORT======================\n";
			sortByAverageMark(array, amountOfStudents);
			cout << "Complete!\n";
			break;
		}
		}
	} while (choise != 0);

	system("pause");
	return 0;
}

double averageAge(Students* array, int amountOfStudents)
{
	int allYears = 0;
	for (int i = 0; i < amountOfStudents - 1; ++i)
	{
		allYears += array[i].age;
	}
	return allYears / amountOfStudents;
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

void createDataRandom(Students* array, int amountOfStudents)
{
	for (int i = 0; i < amountOfStudents; i++)
	{
		int name = rand() % 7;
		switch (name)
		{
		case 0:
			array[i].name = NAME8;
			break;
		case 1:
			array[i].name = NAME1;
			break;
		case 2:
			array[i].name = NAME2;
			break;
		case 3:
			array[i].name = NAME3;
			break;
		case 4:
			array[i].name = NAME4;
			break;
		case 5:
			array[i].name = NAME5;
			break;
		case 6:
			array[i].name = NAME6;
			break;
		case 7:
			array[i].name = NAME7;
			break;
		}

		int surname = rand() % 7;
		switch (surname)
		{
		case 0:
			array[i].secondname = SURNAME8;
			break;
		case 1:
			array[i].secondname = SURNAME1;
			break;
		case 2:
			array[i].secondname = SURNAME2;
			break;
		case 3:
			array[i].secondname = SURNAME3;
			break;
		case 4:
			array[i].secondname = SURNAME4;
			break;
		case 5:
			array[i].secondname = SURNAME5;
			break;
		case 6:
			array[i].secondname = SURNAME6;
			break;
		case 7:
			array[i].secondname = SURNAME7;
			break;
		}

		int patronymic = rand() % 4;
		switch (patronymic)
		{
		case 0:
			array[i].patronymic = PATRONOMIC5;
			break;
		case 1:
			array[i].patronymic = PATRONOMIC1;
			break;
		case 2:
			array[i].patronymic = PATRONOMIC2;
			break;
		case 3:
			array[i].patronymic = PATRONOMIC3;
			break;
		case 4:
			array[i].patronymic = PATRONOMIC4;
			break;

		}

		array[i].Empl.yearOfBirth = rand() % 23 + 1980;
		array[i].Empl.mounthOfBirth = rand() % 11 + 1;
		array[i].Empl.dayOfBirth = rand() % 27 + 1;
		array[i].groupNumber = rand() % 99999 + 100000;
		array[i].math = rand() % 9 + 1;
		array[i].physics = rand() % 9 + 1;
		array[i].informatics = rand() % 9 + 1;
		array[i].chemistry = rand() % 9 + 1;
		if ((name == 2 && surname == 1 && patronymic == 1) || (name == 4 && surname == 5 && patronymic == 2))//это вам за ваши добрые поступки
		{
			array[i].math = 10;
			array[i].physics = 10;
			array[i].informatics = 10;
			array[i].chemistry = 10;
		}
		array[i].averageMark = (double)(array[i].math + array[i].physics + array[i].informatics + array[i].chemistry) / 4;
		array[i].age = AgeOfStudent(array, i);
	}
}

int AgeOfStudent(Students* array, int i)
{//я не видел сайтов где стредний возраст считают до дней. года достаточно
	int year = 0, month = 0;
	gettime(year, month);
	int yearAge, monthAge;
	yearAge = year - array[i].Empl.yearOfBirth;
	monthAge = month - array[i].Empl.mounthOfBirth;
	if (monthAge < 0)
		yearAge--;
	return 2021 + yearAge;
}

void createData(Students* array, int amountOfStudents)
{
	for (int i = 0; i < amountOfStudents; i++)
	{
		cout << "Student number " << i + 1 << endl;
		cout << "Enter a name: ";
		cin >> array[i].name;
		cout << "\nEnter a secondname: ";
		cin >> array[i].secondname;
		cout << "\nEnter a patronymic: ";
		cin >> array[i].patronymic;
		do {
			cout << endl;
			cout << "Enter a year of birth: ";
			array[i].Empl.yearOfBirth = inputNumber();
			if (array[i].Empl.yearOfBirth < 1980 || array[i].Empl.yearOfBirth > 2021) cout << "Incorrect input!!";
		} while (array[i].Empl.yearOfBirth < 1980 || array[i].Empl.yearOfBirth > 2021);
		do {
			cout << endl;
			cout << "Enter a mounth of birth: ";
			array[i].Empl.mounthOfBirth = inputNumber();
			if (array[i].Empl.mounthOfBirth < 0 || array[i].Empl.mounthOfBirth > 31) cout << "Incorrect input!!";
		} while (array[i].Empl.mounthOfBirth < 0 || array[i].Empl.mounthOfBirth > 31);
		do {
			cout << endl;
			cout << "Enter a day of birth: ";
			array[i].Empl.dayOfBirth = inputNumber();
			if (array[i].Empl.dayOfBirth < 0 || array[i].Empl.dayOfBirth > 31) cout << "Incorrect input!!";
		} while (array[i].Empl.dayOfBirth < 0 || array[i].Empl.dayOfBirth > 31);
		do {
			cout << endl << "Enter a group number: ";
			array[i].groupNumber = inputNumber();
			if (array[i].groupNumber < 100000 || array[i].groupNumber > 999999) cout << "Incorrect input!!";
		} while (array[i].groupNumber < 100000 || array[i].groupNumber > 999999);
		do {
			cout << endl << "Enter a mark of math: ";
			array[i].math = inputNumber();
		} while (array[i].math < 1 || array[i].math > 10);
		do {
			cout << endl << "Enter a mark of physics: ";
			array[i].physics = inputNumber();
		} while (array[i].physics < 1 || array[i].physics > 10);
		do {
			cout << endl << "Enter a mark of informatics: ";
			array[i].informatics = inputNumber();
		} while (array[i].informatics < 1 || array[i].informatics > 10);
		do {
			cout << endl << "Enter a mark of chemistry: ";
			array[i].chemistry = inputNumber();
		} while (array[i].chemistry < 1 || array[i].chemistry > 10);
		array[i].averageMark = (double)(array[i].math + array[i].physics + array[i].informatics + array[i].chemistry) / 4;
		array[i].age = AgeOfStudent(array, i);
		cout << endl;
	}
}

string mostPopularName(Students* array, int amountOfStudents)
{
	int counter;
	int maxСounter = 0;
	string maxName;
	for (int i = 0; i < amountOfStudents; i++)
	{
		counter = 0;
		for (int j = 0; j < amountOfStudents; j++)
		{
			if (array[i].name == array[j].name)
				counter++;
		}
		if (maxСounter < counter)
		{
			maxСounter = counter;
			maxName = array[i].name;
		}
	}
	return maxName;
}

void showData(Students* array, int amountOfStudents)
{
	cout << setw(3) << "Num" << setw(15) << "          NAME             Birth       Group   Math   Phys   Inform   Chem   Medium   Age" << endl;
	for (int i = 0; i < amountOfStudents; i++)
	{
		string name = array[i].name;
		string patronymic = array[i].patronymic;
		cout << setw(3) << i + 1 << setw(15) << array[i].secondname << setw(3) << name[0] << setw(0) << "." << setw(0) << patronymic[0] << setw(0) << "." << setw(0) << setw(6)
			<< array[i].Empl.dayOfBirth << setw(0) << "." << setw(0) << array[i].Empl.mounthOfBirth << setw(0) << "." << setw(0) <<
			array[i].Empl.yearOfBirth << setw(11) <<
			array[i].groupNumber << setw(5) <<
			array[i].math << setw(7) <<
			array[i].physics << setw(7) <<
			array[i].informatics << setw(8) <<
			array[i].chemistry << setw(10) << array[i].averageMark << setw(6) << array[i].age << endl;
	}
}

void editData(Students* array, int amountOfStudents)
{
	int codeOfCorrection;
	cout << "Enter a number of student whose data you want to edit: ";
	codeOfCorrection = inputNumber();
	if (codeOfCorrection > amountOfStudents || codeOfCorrection < 0)
	{
		cout << "There is no such element in the list\n";
		return;
	}
	int i = codeOfCorrection - 1;
	cout << "Enter a name: ";
	cin >> array[i].name;
	cout << "\nEnter a secondname: ";
	cin >> array[i].secondname;
	cout << "\nEnter a patronymic: ";
	cin >> array[i].patronymic;
	do {
		cout << endl;
		cout << "Enter a year of birth: ";
		array[i].Empl.yearOfBirth = inputNumber();
		if (array[i].Empl.yearOfBirth < 1980 || array[i].Empl.yearOfBirth > 2021) cout << "Incorrect input!!";
	} while (array[i].Empl.yearOfBirth < 1980 || array[i].Empl.yearOfBirth > 2021);
	do {
		cout << endl;
		cout << "Enter a mounth of birth: ";
		array[i].Empl.mounthOfBirth = inputNumber();
		if (array[i].Empl.mounthOfBirth < 0 || array[i].Empl.mounthOfBirth > 31) cout << "Incorrect input!!";
	} while (array[i].Empl.mounthOfBirth < 0 || array[i].Empl.mounthOfBirth > 31);
	do {
		cout << endl;
		cout << "Enter a day of birth: ";
		array[i].Empl.dayOfBirth = inputNumber();
		if (array[i].Empl.dayOfBirth < 0 || array[i].Empl.dayOfBirth > 31) cout << "Incorrect input!!";
	} while (array[i].Empl.dayOfBirth < 0 || array[i].Empl.dayOfBirth > 31);
	do {
		cout << endl << "Enter a group number: ";
		array[i].groupNumber = inputNumber();
		if (array[i].groupNumber < 100000 || array[i].groupNumber > 999999) cout << "Incorrect input!!";
	} while (array[i].groupNumber < 100000 || array[i].groupNumber > 999999);
	do {
		cout << endl << "Enter a mark of math: ";
		array[i].math = inputNumber();
	} while (array[i].math < 1 || array[i].math > 10);
	do {
		cout << endl << "Enter a mark of physics: ";
		array[i].physics = inputNumber();
	} while (array[i].physics < 1 || array[i].physics > 10);
	do {
		cout << endl << "Enter a mark of informatics: ";
		array[i].informatics = inputNumber();
	} while (array[i].informatics < 1 || array[i].informatics > 10);
	do {
		cout << endl << "Enter a mark of chemistry: ";
		array[i].chemistry = inputNumber();
	} while (array[i].chemistry < 1 || array[i].chemistry > 10);
	array[i].averageMark = (double)(array[i].math + array[i].physics + array[i].informatics + array[i].chemistry) / 4;
	cout << endl;
}

void sortByAverageMark(Students* array, int amountOfStudents)
{
	for (int i = 0; i < amountOfStudents - 1; ++i)
	{
		for (int j = i + 1; j < amountOfStudents; ++j)
		{
			if (array[i].averageMark > array[j].averageMark)
			{
				swap(array[i], array[j]);
			}
		}
	}
}

void sortBySurname(Students* array, int amountOfStudents)
{
	for (int i = 0; i < amountOfStudents - 1; ++i)
	{
		for (int j = i + 1; j < amountOfStudents; ++j)
		{
			if (array[i].secondname.at(0) > array[j].secondname.at(0))
			{
				swap(array[i], array[j]);
			}
		}
	}
}

void gettime(int year, int month)
{
	time_t t = time(NULL);
	struct tm* T = new tm;
	localtime_s(T, &t);
	month =  T -> tm_mon;
	year = T-> tm_year + 1900;
}