#include <iostream>
#include <vector>
using namespace std;

void printSequence(const vector<int>& sequence) {
    for (int val : sequence) {
        cout << val << " ";
    }
    cout << endl;
}

void allSequence(int ind, int arr[], int n, vector<int>& currentSequence) {
    if (ind == n) {
        printSequence(currentSequence);
        return;
    }

    currentSequence.push_back(arr[ind]);
    allSequence(ind + 1, arr, n, currentSequence);
    currentSequence.pop_back();
    allSequence(ind + 1, arr, n, currentSequence);
}

int main() {
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> currentSequence;

    allSequence(0, arr, n, currentSequence);

    return 0;
}