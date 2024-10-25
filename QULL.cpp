#include "SLL.h"
#include <iostream>
using namespace std;

class Q {
    Node* front;
    Node* rear;
    int size;

    public:
    Q() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    void push (int x) {
        Node* temp = new Node(x);
        if (front == NULL) {
            front = rear = temp;
        }
        else {
            rear -> next = temp;
            rear = temp;
        }
        size += 1;
    }

    void pop () {
        if (front == NULL) {
            cout << "There exist no queue.";
        }
        else {
            Node* temp = front;
            front = front -> next;
            delete temp;
            size -= 1;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
    }

    int top () {
        if (front == NULL) {
            cout << "There exist no queue.";
            return -1;
        }
        else {
            return front -> data;
        }
    }

    int Qsize () {
        return size;
    }

    void printQ () {
        if (front == NULL) {
            cout << "There exist no queue.";
        }
        else {
            Node* temp = front;
            while (temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        }
    }

    void print (int x) {
        cout << x << endl;
    }
};

int main() {
    Q q;
    q.push(9);
    q.push(7);
    q.printQ();
    q.pop();
    q.push(4);
    q.push(23);
    q.print(q.top());
    q.print(q.Qsize());
    q.printQ();
    return 0;
}