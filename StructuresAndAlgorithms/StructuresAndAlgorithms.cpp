#include <iostream>
#include <stack>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

bool isOperator(char a) {
    if (a == '+' or a == '-' or a == '*' or a == '/' or a == '^') return 1;
    return 0;
}

stack <string> S;
string S_start, S_temp, temp_operand;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    while (true) {
        S_temp = "";
        temp_operand.clear();
        cout << "Введите постфиксное выражение (без пробелов!!!): ";
        cin >> S_start;
        for (char i : S_start) {
            
        }
        cout << S.top() << endl;
    }
}