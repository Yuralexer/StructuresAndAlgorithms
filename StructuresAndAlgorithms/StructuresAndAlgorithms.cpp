#include <iostream>
#include <queue>
#include <Windows.h>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

bool isOperator(char a) {
    if (a == '+' or a == '-' or a == '*' or a == '/' or a == '^') return 1;
    return 0;
}

queue <string> S;
string S_start, S_temp, temp_operand1, temp_operand2, temp_operation;
double result;
double num;
bool readingNum;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    while (true) {
        S_temp = "";
        num = 0;
        result = 0;
        readingNum = false;
        cout << "Введите префиксное выражение с числами (пробелы ставьте только между числами!!!): ";
        getline(cin, S_start);
        for (char i : S_start) {
            if (isOperator(i)) {
                if (readingNum) {
                    readingNum = false;
                    S_temp = to_string(num);
                    S.push(S_temp);
                    num = 0;
                }
                S_temp = i;
                S.push(S_temp);
            }
            else if (i != ' ') {
                readingNum = true;
                num = num * 10 + (i - '0');
            }
            else {
                readingNum = false;
                S_temp = to_string(num);
                S.push(S_temp);
                num = 0;
            }
        }
        if (readingNum) {
            readingNum = false;
            S_temp = to_string(num);
            S.push(S_temp);
            num = 0;
        }
        while (S.size() > 1) {
            temp_operation = S.front();
            S.pop();
            temp_operand1 = S.front();
            if (temp_operand1.length() == 1 and isOperator(temp_operand1[0])) {
                S.push(temp_operation);
                continue;
            }
            S.pop();
            temp_operand2 = S.front();
            if (temp_operand2.length() == 1 and isOperator(temp_operand2[0])) {
                S.push(temp_operation);
                S.push(temp_operand1);
                continue;
            }
            S.pop();
            switch (temp_operation[0]) {
            case '+':
                num = stod(temp_operand1.c_str()) + stod(temp_operand2.c_str());
                break;
            case '-':
                num = stod(temp_operand1.c_str()) - stod(temp_operand2.c_str());
                break;
            case '*':
                num = stod(temp_operand1.c_str()) * stod(temp_operand2.c_str());
                break;
            case '/':
                num = stod(temp_operand1.c_str()) / stod(temp_operand2.c_str());
                break;
            case '^':
                num = pow(stod(temp_operand1.c_str()), stod(temp_operand2.c_str()));
                break;
            default: break;
            }
            S.push(to_string(num));
        }
        cout << num << endl;
        S.pop();
    }
}