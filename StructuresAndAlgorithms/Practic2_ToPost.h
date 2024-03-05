#include <iostream>
#include <stack>
#include <Windows.h>
#include <vector>

using namespace std;

short int priority(char a) {
    switch (a)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
        break;
    }
}

bool isOperator(char a) {
    if (a == '+' or a == '-' or a == '*' or a == '/' or a == '^') return 1;
    return 0;
}

stack <char> S; // + (0); - (1); * (2); / (3); ^ (4)
vector <short int> argCounter = { 0 };
string S_start, S_final;
int group_num = 0; // Номер скобки, в которй мы находимся
vector <char> lastCharOperation;

void AppendOperator(int i) {
    argCounter[argCounter.size() - 1]++;
    if (argCounter[argCounter.size() - 1] >= 2) {
        if (S_start.length() - i - 1 > 0) {
            if (priority(S_start[i + 1]) <= priority(lastCharOperation[lastCharOperation.size() - 1])) {
                S_final += S.top();
                S.pop();
                argCounter[argCounter.size() - 1] = 1;
            }
        }
        else {
            S_final += S.top();
            S.pop();
            argCounter[argCounter.size() - 1] = 0;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        S_final = "";
        lastCharOperation.push_back(' ');
        cout << "Введите выражение (без пробелов!!!): ";
        cin >> S_start;
        for (int i = 0; i < S_start.length(); i++) {

            if (isOperator(S_start[i])) {
                S.push(S_start[i]);
                lastCharOperation[lastCharOperation.size() - 1] = S_start[i];
            }
            else if (S_start[i] == '(') {
                group_num++;
                argCounter.push_back(0);
                lastCharOperation.push_back(' ');
            }
            else if (S_start[i] == ')') {
                group_num--;
                argCounter.pop_back();
                lastCharOperation.pop_back();
                AppendOperator(i);
            }
            else {
                S_final += S_start[i];
                AppendOperator(i);
            }
        }
        while (!S.empty()) {
            S_final += S.top();
            S.pop();
        }
        cout << S_final << endl;
    }
}