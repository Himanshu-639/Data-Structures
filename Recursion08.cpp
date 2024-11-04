#include <iostream>
using namespace std;

void swapArray(int arr[], int i, int n) {
    if (i > n/2) {
        return;
    }
    swap(arr[i], arr[n - i - 1]);
    swapArray(arr, i + 1, n);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    swapArray(arr, 0, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}