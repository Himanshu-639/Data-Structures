#include <iostream>
#include <queue>
using namespace std;

class st {
    queue <int> q;

    public:
    void push (int x) {
        int s = q.size();
        q.push(x);
        for (int i = 1; i <= s; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    void pop() {
        if (q.empty()) {
            cout << "The stack is empty." << endl;
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "The stack is empty." << endl;
            return -1;
        } 
        return q.front();
    }

    bool empty() {
        return q.empty();
    }

    void print() {
        queue<int> temp = q;
        while(!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    st stack;
    stack.push(30);
    stack.push(40);
    cout << stack.top() <<endl;
    stack.push(56);
    stack.print();
    stack.pop();
    stack.push(90);
    stack.print();
}