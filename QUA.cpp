#include <iostream>
using namespace std;

class QImp {
    int front;
    int rear;
    static const int size = 10;
    int Q[size];
    int curSize;

public:
    QImp() {
        front = -1;
        rear = -1;
        curSize = 0;
    }

    void push(int x) {
        if (curSize == size) {
            cout << "The queue is already full." << endl;
        }
        if (curSize == 0) {
            front = 0;
            rear = 0; 
        } else {
            rear = (rear + 1) % size;
        }
        Q[rear] = x;
        curSize += 1;
    }

    int frontEl() {
        if (curSize == 0) {
            return -1;
        }
        else {
            return Q[front];
        }
    }

    int rearEl() {
        if (curSize == 0) {
            return -1;
        }
        else {
            return Q[rear];
        }
    }

    int pop() {
        if (curSize == 0) {
            cout << "There exist no Queue.";
            return -1;
        }
        int el = Q[front];
        if (curSize == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        curSize -= 1;
        return el;
    }

    int Qsize() {
        return curSize;
    }

    void clearQueue () {
        front = -1;
        rear = -1;
        curSize = 0;
        cout << "Stack is cleared." <<endl;
    }

    void printEl() {
        if (curSize == 0) {
            cout << "There exist no queue." << endl;
        } else {
            int count = curSize;
            int i = front;
            while (count > 0) {
                cout << Q[i] << " ";
                i = (i + 1) % size;
                count--;
            }
            cout << endl;
        }
    }

    void print(int result) {
        cout << result << endl;
    }
};

int main() {
    QImp queue;
    queue.push(10);
    queue.printEl();
    queue.push(20);
    queue.printEl();
    int result1 = queue.frontEl();
    queue.print(result1);    
    queue.clearQueue();
    int result2 = queue.Qsize();
    queue.print(result2);
    return 0;
}
