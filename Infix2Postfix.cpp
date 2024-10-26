#include <iostream>
#include <stack>
using namespace std;

int priority(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

string InfixToPostfix(string s) {
    int i = 0;
    stack<char> operatorStack;
    string ans = "";

    int n = s.length();

    while (i < n) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || s[i] >= '0' && s[i] <= '9') {
            ans = ans + s[i];
        }
        else if (s[i] == '(') {
            operatorStack.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                ans = ans + operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else {
            while (!operatorStack.empty() && priority(s[i]) <= priority(operatorStack.top())) {
                ans = ans + operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(s[i]);
        }
        i++;
    }
    while (!operatorStack.empty()) {
        ans = ans + operatorStack.top();
        operatorStack.pop();
    }
    return ans;
}

int main() {
    string st = "a+b*(c^d-e)";
    string a = InfixToPostfix(st);
    cout << a << endl;
    return 0;
}