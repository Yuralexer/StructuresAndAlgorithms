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
        cout << "������� ����� �������� (1 - �������� ��������, 2 - ����������� �������, 3 - ������� ��������): ";
        i = _getch() - '0';
        system("cls");
        switch (i) {
        case 1:
            temp_Operation = addoperation();
            addOperationInDataBase(T, temp_Operation);
            printDataBase(T, temp_Operation.cash_register_code);
            break;
        case 2:
            cout << "������� ����� ����� ��� �����������: ";
            j = _getch() - '0';
            printDataBase(T, j);
            break;
        case 3:
            cout << "������� ����� �����, ������� ����� �������: ";
            j = _getch() - '0';
            deleteOperations(T, j);
            system("cls");
            break;
        default: break;
        }
    }
}

