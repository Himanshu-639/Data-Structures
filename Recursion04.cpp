#include <iostream>
using namespace std;

void printfromn (int i, int n) {
    if (i > n) {
        return;
    }
    printfromn(i + 1, n);
    cout << i << " ";
}

int main() {
    int n;
    cout << "Enter a number : ";
    cin >> n;
    printfromn(1, n);
}