#include <iostream>
#include <vector>
using namespace std;

class Heap {
    private:

    vector<int> heap;

    /*Swaps Child and Parent if the child element is greater than parent*/
    void heapify(vector<int>& arr, int size, int i) {
        int largest = i;
        int left = (2 * i) + 1;
        int right = (2 * i) + 2;

        if(left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        if(right < size && arr[right] > arr[largest]) {
            largest = right;
        }
        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, size, largest);
        }
    }

    public:

    void heapSort(vector<int>& arr) {
        int n = arr.size();

        /*Build Max - Heap*/
        for (int i = n/2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    void printArray(const vector<int>& arr) {
        for (int val : arr) {
            cout << val << " ";
        }
        cout << endl;
    }
};

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

    Heap heap;
    heap.heapSort(arr);

    cout << "Sorted Array : " ;
    heap.printArray(arr);

    return 0;
}