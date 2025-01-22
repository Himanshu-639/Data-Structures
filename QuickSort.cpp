#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int partIndex = partition(arr, low, high);
        quickSort(arr, low, partIndex - 1);
        quickSort(arr, partIndex + 1, high);
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

    quickSort(arr, 0, size - 1);

    for(int val : arr) {
        cout << val <<" ";
    }
    cout << endl;
}