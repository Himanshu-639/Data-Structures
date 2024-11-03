#include <iostream>
using namespace std;

int sumtilln(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumtilln(n - 1);
}

int main() {
    int n;
    cout << "Enter a number : ";
    cin >> n;
    int result = sumtilln(n);
    cout << "Sum of numbers till " << n << " : " << result ;
}