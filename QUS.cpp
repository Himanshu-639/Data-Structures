#include <iostream>
#include <stack>
using namespace std;

class queue {
    stack<int> s1, s2;

    public:
    void push (int x) {
        while (s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    void print() {
        stack<int> temp = s1;
        while(!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    queue q;
    q.push(5);
    q.push(0);
    q.push(7);
    q.print();
    q.pop();
    cout << q.top() << endl;
    q.push(78);
    q.print();
}