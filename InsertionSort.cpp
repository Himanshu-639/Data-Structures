#include <iostream>
#include <vector>
using namespace std;

void InsertionSort (vector<int>& arr, int size) {
    for (int i = 0; i < size; i++) {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

int main() {
    vector<int> arr;
    int size;
    cout << "Enter the size of array : ";
    cin >> size;

    cout << "Enter the elements of array : ";
    for (int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    InsertionSort(arr, size);

    cout << "Array after sorting : ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}