#include <iostream>
#include <iostream>
#include <ctime>
#include <cassert>
#include <stdlib.h>
#include <math.h>
#define RAND_MAX 32767 
using namespace std;

void zadanie1()
{
    int length, height, counterleight, counterHeight, perimetr, area;
    do {
        cout << "Enter a length:";
        cin >> length;
    } while (length < 0);
    do {
        cout << "Enter a height:";
        cin >> height;
    } while (height < 0);

    for (int counterHeight = 0; height > counterHeight; counterHeight++)
    {
        for (int counterleight = 0; length > counterleight; counterleight++)
        {
            cout << "X";
        }
        cout << "\n";
    }
    perimetr = 2 * height + 2 * length;
    cout << "perimetr = " << perimetr << "\n";
    area = height * length;
    cout << "area = " << area << "\n\nTask 1 is completed\n";
}

void zadanie2()
{
    int number, counter, a = 0, b = 1, elementFib;
    unsigned long long factorial = 1;
    do {
        cout << "Enter a number(0-25): ";
        cin >> number;
    } while (number > 25 || number < 0);
    cout << "\n";
    if (number > 0)
        cout << "0 ";
    if (number > 1)
        cout << "0 ";
    for (counter = 1; counter <= number - 2; ++counter)
    {
        elementFib = a + b;
        a = b;
        b = elementFib;
        cout << elementFib << " ";
        factorial *= counter;
    }
    cout << "\nFactorial = " << factorial << "\nTask 2 is completed\n";
}

void zadanie3()
{
    int counter = 0, counterForSign1 = 0, counterForSign2 = 0, firstNumber, secondNumber;
    do {
        cout << "Enter a first number: ";
        cin >> firstNumber;
    } while (firstNumber < 0);
    do {
        cout << "Enter a second number: ";
        cin >> secondNumber;
    } while (firstNumber < 0);
    if (firstNumber == 0)
        cout << "\n\nNull is not composite and  not simple\n";
    else
    {
        for (int i = 1; i < firstNumber; i++)
        {
            if (firstNumber % i == 0)
                counter++;
        }
        if (counter > 1)
            cout << "\n" << firstNumber << " is composite\n";
        else
            cout << "\n" << firstNumber << " is simple\n";
    }
    counter = 0;
    if (secondNumber == 0)
        cout << "Null is not composite and not simple\n";
    else
    {
        for (int i = 1; i < secondNumber; i++)
        {
            if (secondNumber % i == 0)
                counter++;
        }
        if (counter > 1)
            cout << secondNumber << " is composite\n";
        else
            cout << secondNumber << " is simple\n";
    }
    while (firstNumber != 0 and secondNumber != 0)
    {
        if (firstNumber > secondNumber)
        {
            firstNumber = firstNumber % secondNumber;
        }
        else
        {
            secondNumber = secondNumber % firstNumber;
        }
    }
    while(firstNumber != 0 && secondNumber != 0)
    {
        if (firstNumber > secondNumber)
            firstNumber %= secondNumber;
        else
            secondNumber %= firstNumber;
    }
    cout << "GCF = " << firstNumber + secondNumber << "\n\nTask 3 is completed\n";
}

void zadanie4()
{
    unsigned long number;
    short oneSymbol;
    do {
        cout << "Enter a number(0-100000000): ";
        cin >> number;
    } while(number < 0 || number > 100000000);//why for large(999999999999999999999999) numbers the error?!?!
    if (number == 0)
        cout << "0";
    else
    {
        int size, i = 0;
        int* array = new int[number];
        while (number >= 1)
        {
            oneSymbol = number % 2;
            number = number / 2;
            array[i] = oneSymbol;
            i++;
        }

        for (int j = i - 1; j > 0; j--)
        {
            cout << array[j];
        }
    }
    cout << "\nTask 4 is completed\n";
}
//If I cannot use random I will make my own.
//                           Nikita Verkhovodko                        
struct PRNG
{
    unsigned seed = 0;
};

void initGenerator(PRNG& generator)
{
    generator.seed = unsigned(std::time(nullptr));
}

unsigned random(PRNG& generator, unsigned minValue, unsigned maxValue)
{
    assert(minValue < maxValue);
    generator.seed = (generator.seed * 73129 + 95121);
    return (generator.seed % (maxValue + 1 - minValue)) + minValue;
}

void zadanie5()
{
    PRNG generator;
    initGenerator(generator);  
    int SIZE;
    do {
        cout << "How many numbers generate(1 - 100000): ";
        cin >> SIZE;
    } while (SIZE > 100000 || SIZE < 1);
    int array[100000];
    int num[10]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = random(generator, 1, 10);
        cout << array[i] << " ";
        switch (array[i])
        {
        case 1:
            num[0]++;
            break;
        case 2:
            num[1]++;
            break;
        case 3:
            num[2]++;
            break;
        case 4:
            num[3]++;
            break;
        case 5:
            num[4]++;
            break;
        case 6:
            num[5]++;
            break;
        case 7:
            num[6]++;
            break;
        case 8:
            num[7]++;
            break;
        case 9:
            num[8]++;
            break;
        case 10:
            num[9]++;
            break;
        }
    }
    for (int counter = 0; counter < 10; counter++)
    {
        cout << "\n-" << counter + 1  << "-";
        for (int num0 = 0; num[counter] * 100 / SIZE > num0; num0++)
        {
            cout << "X";
        }
    }
    cout << "\n\nTask 5 is completed\n";
}

int main()
{
    int toggle;
    while (true) {
        do {
            cout <<"________________________________________________________________________________________________________________________\n" << 
                "Enter a task number(1-5) " << "\nTo exit press 0\n" << "Your choise: ";
            cin >> toggle;
        } while (toggle > 5 || toggle < 0);
        cout << "\n";
        if (toggle == 0)
            return 0;
        else {
            switch (toggle)
            {
            case 1:
                zadanie1();
                break;
            case 2:
                zadanie2();
                break;
            case 3:
                zadanie3();
                break;
            case 4:
                zadanie4();
                break;
            case 5:
                zadanie5();
                break;
            }
        }
    }
    system("pause");
    return 0;
}
