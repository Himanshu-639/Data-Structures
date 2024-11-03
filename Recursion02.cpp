#include <iostream>
using namespace std;

void printfromn(int i, int n) {
    if (i < 1) {
        return;
    }
    cout << i <<" ";
    printfromn(i-1, n);
}

int main() {
    int n;
    cout << "Enter the a number : ";
    cin >> n;
    printfromn(n, n);
}