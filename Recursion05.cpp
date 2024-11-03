#include <iostream>
using namespace std;

void sumtilln(int n, int sum) {
    if (n < 1) {
        cout << sum;
        return;
    }
    sumtilln(n - 1, sum + n);
}

int main() {
    int n;
    cout << "Enter a number : ";
    cin >> n;
    sumtilln(n, 0);
}