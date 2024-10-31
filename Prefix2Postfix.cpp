#include <iostream>
#include <stack>
using namespace std;

string PrefixToPostfix(string s) {
    stack<string> resultStack;
    int n = s.length();
    int i = n - 1;

    while(i >= 0) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            resultStack.push(string(1, s[i]));
        }
        else {
            string t1 = resultStack.top();
            resultStack.pop();
            string t2 = resultStack.top();
            resultStack.pop();
            string con = t1 + t2 + s[i];
            resultStack.push(con);
        }
        i--;
    }
    return resultStack.top();
}

int main() {
    string prefix = "/-AB*+DEF";
    string postfix = PrefixToPostfix(prefix);
    cout << "Postfix Expression : " << postfix << endl;
    return 0;
}