#include <iostream>

using namespace std;

int main()
{

    setlocale(LC_ALL, "rus");
    int Mounths;
    cout << "Введите номер месяца\n";
    cin >> Mounths;

    switch (Mounths) {

    case 1:
        cout << "Зима, январь" << endl;
        break;

    case 2:
        cout << "Зима, февраль" << endl;
        break;

    case 3:
        cout << "Весна, март" << endl;
        break;

    case 4:
        cout << "Весна, апрель" << endl;
        break;

    case 5:
        cout << "Весна, май" << endl;
        break;

    case 6:
        cout << "Лето, июнь" << endl;
        break;

    case 7:
        cout << "Лето, июль" << endl;
        break;

    case 8:
        cout << "Лето, август" << endl;
        break;

    case 9:
        cout << "Осень, сентябрь" << endl;
        break;

    case 10:
        cout << "Осень, октябрь" << endl;
        break;

    case 11:
        cout << "Осень, ноябрь" << endl;
        break;

    case 12:
        cout << "Зима, декабрь" << endl;
        break;

    default:
        cout << "Ошибка. Проверьте введённые данные" << endl;
    }
    return 0;
}