#include "SLL.h"
#include <iostream>
using namespace std;

class stack {
    Node* top;
    int size;

    public:
    stack() {
        top = nullptr;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp -> next = top;
        top = temp;
        size += 1;
    }

    void pop() {
        if (size == 0) {
            cout << "The Stack is empty.";
        } else
        {
            Node* temp = top;
            top = top -> next;
            delete temp;
            size -= 1;
        }
    }

    int topEl() {
        if (size == 0) {
            cout << "The Stack is empty.";
            return -1;
        }
        else {
            return top -> data;
        }
    }

    int stSize() {
        return size;
    }

    void printSt() {
        if (top == 0) {
            cout << "The Stack is empty.";
        }
        else {
            Node* temp = top;
            while (temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
            }
        }
    }
};

int main() {
    stack st;
    st.push(7);
    st.push(8);
    st.printSt();
    return 0;
}