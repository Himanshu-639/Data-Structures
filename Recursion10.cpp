#include <iostream>
using namespace std;

int nthFibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the position of Fibonacci Number : ";
    cin >> n;
    int result = nthFibonacci(n);
    cout << n <<"th Fibonacci number : " << result << endl;
    return 0;
}