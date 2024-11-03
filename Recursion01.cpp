#include <iostream>
using namespace std;

void printtilln(int i, int n) {
    if (i > n) {
        return;
    }
    cout << i << " ";
    printtilln(i + 1, n);
}

int main() {
    int n;
    cout << "Enter the last value : ";
    cin >> n;
    printtilln(1, n);
}