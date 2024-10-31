#include <iostream>
#include <stack>
using namespace std;

string PostfixToPrefix(string s) {
    int i = 0;
    stack<string> resultStack;
    int n = s.length();

    while(i < n) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            resultStack.push(string(1, s[i]));
        }
        else {
            string t1 = resultStack.top();
            resultStack.pop();
            string t2 = resultStack.top();
            resultStack.pop();
            string con = s[i] + t2 + t1;
            resultStack.push(con);
        }
        i++;
    }
    return resultStack.top();
}

int main() {
    string postfix = "AB-DE+F*/";
    string prefix = PostfixToPrefix(postfix);
    cout << "Prefix Expression : " << prefix <<endl;
    return 0;
}