#include <iostream>
using namespace std;

#define N 5
int deque[N];
int f = -1 , r= -1;

void enquefront(int x) {
    if ((f == 0 && r == N - 1) || (f == r + 1)) {
        cout << "Queue is full." <<endl;
    }
    else if (f == -1 && r == -1) {
        f = r = 0;
        deque[f] = x;
    }
    else if (f == 0) {
        f = N - 1;
        deque[f] = x;
    }
    else {
        f--;
        deque[f] = x;
    }
}

void enquerear(int x) {
    if ((f == 0 && r == N - 1) || f == r + 1) {
        cout << "Queue is full." << endl;
    }
    else if (f == -1 && r == -1) {
        f = r = 0;
        deque[r] = x;
    }
    else if (r == N - 1) {
        r = 0;
        deque[r] = x;
    }
    else {
        r++;
        deque[r] = x;
    }
}

void getfront() {
    if (f == -1 && r == -1) {
        cout << "Queue is empty." <<endl;
    }
    else {
        cout << deque[f] << endl;
    }
}

void dequefront() {
    if (f == -1 && r == -1) {
        cout << "Queue is empty." << endl;
    }
    else if (f == r) {
        f = r = -1;
    }
    else if (f == N -1) {
        f = 0;
    }
    else {
        f++;
    }
}

void dequerear() {
    if (f == -1 && r == -1) {
        cout << "Queue is empty." << endl;
    }
    else if (f == r) {
        f = r = -1;
    }
    else if (r == 0) {
        r = N - 1;
    }
    else {
        r--;
    }
}

void display() {
    if (f == -1 && r == -1) {
        cout << "Queue is empty." <<endl;
    }
    else {
        int i = f;
        cout << "Dequeue elements : ";
        while (true) {
            cout << deque[i] << " ";
            if (i == r) break;
            i = (i + 1) % N;
        }
    }
}

int main() {
    enquefront(6);
    enquefront(67);
    display();
    enquerear(90);
    enquerear(11);
    dequefront();
    dequerear();
    display();
    getfront();
}