#include <iostream>
#include <vector>
using namespace std;

class Heap {
    private:

    vector<int> heap;

    /*Swaps Child and Parent if the child element is greater than parent*/
    void heapifyDown(int i) {
        int largest = i;
        int left = (2 * i) + 1;
        int right = (2 * i) + 2;

        if(left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if(right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if(largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    public:
    void buildMaxHeap(const vector<int> & arr) {
        heap = arr;
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void printHeap() {
        for (int val : heap) {
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
    heap.buildMaxHeap(arr);

    cout << "Max Heap : " ;
    heap.printHeap();

    return 0;
}