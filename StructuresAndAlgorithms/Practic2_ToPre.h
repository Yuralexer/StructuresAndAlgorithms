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
        cout << "¬ведите постфиксное выражение (без пробелов!!!): ";
        cin >> S_start;
        for (char i : S_start) {
            if (!isOperator(i)) {
                S_temp = i;
                S.push(S_temp);
            }
            else {
                S_temp = S.top();
                S.pop();
                S_temp = i + S.top() + S_temp;
                S.pop();
                S.push(S_temp);
            }
        }
        cout << S.top() << endl;
        S.pop();
    }
}