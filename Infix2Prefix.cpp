#include <iostream>
#include <stack>
#include <algorithm>
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

string InfixToPrefix(string s) {
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        }
        else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    int i = 0;
    stack<char> operatorStack;
    string ans = "";

    int n = s.length();

    while(i < n) {
        if ((s[i] >= 'A' && s[i] <='Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        }
        else if (s[i] == '(') {
            operatorStack.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                ans += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else {
            // Modified "<=" to "<"
            while (!operatorStack.empty() && priority(s[i]) < priority(operatorStack.top())) {
                ans += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(s[i]);
        }
        i++;
    }
    while (!operatorStack.empty()) {
        ans += operatorStack.top();
        operatorStack.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string q = "(A+B)*C-D+F";
    string a = InfixToPrefix(q);
    cout << "Prefix Expression : " << a << endl;
    return 0;
}
