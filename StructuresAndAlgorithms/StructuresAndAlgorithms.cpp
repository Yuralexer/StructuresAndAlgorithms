#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Structure1.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    table a;
    operation i;
    int count, n, n2;
    cin >> count >> n >> n2;
    for (int j = 0; j < count; j++) {
        i = addoperation();
        addOperationInDataBase(a, i);
    }
    printDataBase(a, n);
    _getch();
    deleteOperations(a, n);
    printDataBase(a, n);
    _getch();
    printDataBase(a, n2);

}

