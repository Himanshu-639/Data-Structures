#include <iostream>
#include <stack>
using namespace std;

string PostfixToInfix(string s) {
    int i = 0;
    stack<string> operatorStack;
    int n = s.length();

    while(i < n) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            operatorStack.push(string(1, s[i]));
        }
        else {
            string t1 = operatorStack.top();
            operatorStack.pop();
            string t2 = operatorStack.top();
            operatorStack.pop();
            string con = "(" + t2 + s[i] + t1 + ")";
            operatorStack.push(con);
        }
        i++;
    }
    return operatorStack.top();
}

int main() {
    string postfix = "AB-DE+F*/";
    string infix = PostfixToInfix(postfix);
    cout << "Infix expression : " << infix << endl;
    return 0;
}