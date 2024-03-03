#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Structure3.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    table T;
    operation temp_Operation;
    int i, j;
    while (true) {
        cout << "¬ведите цифру операции (1 - добавить опреацию, 2 - распечатать таблицу, 3 - удалить операцию): ";
        i = _getch() - '0';
        system("cls");
        switch (i) {
        case 1:
            temp_Operation = addoperation();
            addOperationInDataBase(T, temp_Operation);
            printDataBase(T, temp_Operation.cash_register_code);
            break;
        case 2:
            cout << "¬ведите цифру кассы дл€ отображени€: ";
            j = _getch() - '0';
            printDataBase(T, j);
            break;
        case 3:
            cout << "¬ведите цифру кассы, которую нужно удалить: ";
            j = _getch() - '0';
            deleteOperations(T, j);
            system("cls");
            break;
        default: break;
        }
    }
}

