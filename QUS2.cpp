#include <iostream>
#include <stack>
using namespace std;

class queue {
    stack<int> s1, s2;

    public:
    void push(int x) {
        s1.push(x);
    }

    void pop() {
        if (!s2.empty()) {
            s2.pop();
        }
        else {
            while (s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }

    int top() {
        if (!s2.empty()) {
            return s2.top();
        }
        else {
            while (s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
};