#include <iostream>
using namespace std;

void printtilln(int i, int n) {
    if (i < 1) {
        return;
    }
    printtilln(i - 1, n);
    cout << i << " ";
}

int main() {
    int n;
    cout << "Enter the last number : ";
    cin >> n;
    printtilln(n, n);
}