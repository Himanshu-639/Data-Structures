#include <iostream>
using namespace std;

void swapArray(int l, int r, int a[]) {
    if (l >= r) {
        return;
    }
    swap(a[l], a[r]);
    swapArray(l + 1, r - 1, a);
}

int main() {
    int a[] = {3, 4, 5, 6, 8, 8, 0, 9};
    int b = sizeof(a) / sizeof(a[0]);
    swapArray(0, b - 1, a);
    for (int i = 0; i < b; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}