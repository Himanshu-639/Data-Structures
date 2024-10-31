#include <iostream>
#include <stack>
using namespace std;

string PrefixToInfix(string s) {
    int n = s.length();
    int i = n - 1;
    stack<string> resultStack;

    while(i >= 0) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] > 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            resultStack.push(string(1, s[i]));
        }
        else {
            string t1 = resultStack.top();
            resultStack.pop();
            string t2 = resultStack.top();
            resultStack.pop();
            string con = "(" + t1 + s[i] + t2 + ")";
            resultStack.push(con);
        }
        i--;
    }
    return resultStack.top();
}


int main() {
    string prefix = "*+PQ-MN";
    string infix = PrefixToInfix(prefix);
    cout << "Infix expression : " << infix << endl;
    return 0;
}