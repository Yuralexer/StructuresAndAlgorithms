#include <iostream>
#include <stack>
#include <Windows.h>
#include <vector>

using namespace std;

bool isOperator(char a) {
    if (a == '+' or a == '-' or a == '*' or a == '/' or a == '^') return 1;
    return 0;
}

stack <string> S;
string S_start, S_temp, temp_operand;

bool PlusOrMinus(string s) {
    int c = 0;
    for (char i : s) {
        if ((i == '+' or i == '-') and c == 0) return 1;
        else if (i == '(') c++;
        else if (i == ')') c--;
    }
    return 0;
}

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
            else if (i == '+' or i == '-') {
                S_temp = i + S.top();
                S.pop();
                S_temp = S.top() + S_temp;
                S.pop();
                S.push(S_temp);
            }
            else if (i == '*' or i == '/') {
                temp_operand = S.top();
                S.pop();
                if (temp_operand.length() > 1 and PlusOrMinus(temp_operand))
                    temp_operand = '(' + temp_operand + ')';
                S_temp = i + temp_operand;
                temp_operand = S.top();
                S.pop();
                if (temp_operand.length() > 1 and PlusOrMinus(temp_operand))
                    temp_operand = '(' + temp_operand + ')';
                S_temp = temp_operand + S_temp;
                S.push(S_temp);
            }
            else {
                temp_operand = S.top();
                S.pop();
                if (temp_operand.length() > 1)
                    temp_operand = '(' + temp_operand + ')';
                S_temp = i + temp_operand;
                S_temp = S.top() + S_temp;
                S.pop();
                S.push(S_temp);
            }
        }
        cout << S.top() << endl;
        S.pop();
    }
}