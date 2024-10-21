#include <iostream>
using namespace std;

class StImpl {
    int top = -1;
    int st[10];

    public:
    StImpl() {
        top = -1;
    }

    void push(int x) {
        if (top >= 9) {
            cout<<"The stack is full.";
        }
        else {
            top += 1;
            st[top] = x;
        }
    }

    int peek() {
        if (top == -1) {
            return -1;
        }
        else {
            return st[top];
        }
    }

    int pop() {
        if (top == -1) {
            cout<<"The stack is empty.";
            return -1;
        }
        else {
            int el = st[top];
            top -= 1;
            return el;
        }
    }

    int size() {
        int s = top +1;
        return s;
    }

    void clearStack() {
        top = -1;
        cout << "Stack is cleared." << endl;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top >= 9;
    }

    void printEl() {
        if (top == -1) {
            cout << "The stack is empty." << endl;
        }
        else {
            for (int i = 0; i <= top; i++) {
                cout << st[i] << " ";
            }
            cout << endl;
        }
    }

    void print(int result) {
        cout << result << endl ;
    }
};

int main() {
    StImpl stack;
    stack.push(10);
    stack.push(20);
    stack.push(9);
    int result = stack.peek();
    stack.print(result);
    stack.printEl();
    return 0;
}