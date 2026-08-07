#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int n, vector<int> & arr) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void selectionSort(int n, vector<int> &arr) {
    for(int i = 0; i < n; i++) {
        int minIdx = i;
        for(int j = i; j < n; j++) {
            if(arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(int n, vector<int> & arr){
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // write while loop for this because it is easier
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// O(N logN) -> avg
// Worst case is O(N^2) if pivot is always being smallest or largest element

// this makes all elements to the left of the pivot <= the pivot value
int partition(int low, int high, int n, vector<int>&arr) {
    // putting all elements <= pivot in the right position
    int idx = low; 
    int pivot = arr[high];
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            swap(arr[j], arr[idx]);
            idx++;
        }
    }
    // fixing the pivot's pos
    idx++;
    swap(arr[idx], arr[high]);
    return idx;
}

void quickSort(int low, int high, int n, vector<int> & arr) {
    if(low >= high) return;
    int pivotIdx = partition(low, high, n, arr);
    // FIX: Exclude the pivot from both sides
    quickSort(low, pivotIdx - 1, n, arr);
    quickSort(pivotIdx + 1, high, n, arr);
}

void merge(int low, int mid, int high, vector<int> & arr) {

    int i = low, j = mid+1;
    vector<int> mergedElements;
    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            mergedElements.push_back(arr[i++]);
        } else mergedElements.push_back(arr[j++]);
    }

    while(i <= mid) {
        mergedElements.push_back(arr[i++]);
    }
    while(j <= high) {
        mergedElements.push_back(arr[j++]);
    }


    for(int i = low; i <= high; i++) {
        arr[i] = mergedElements[i-low];
    }
}


void mergeSortHelper(int low, int high, vector<int> & arr) {
    // missed the base case keep in mind
    if(low >= high) return;
    int mid = low + (high - low)/2;
    mergeSortHelper(low, mid, arr);
    mergeSortHelper(mid+1, high, arr);
    merge(low, mid, high, arr);
}

void mergeSort(int n, vector<int> & arr) {
    mergeSortHelper(0,n-1, arr);
}

int main() {
    vector<vector<int>> tests = {
        {},
        {5},
        {1, 2},
        {2, 1},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {3, 1, 4, 2, 5},
        {7, 7, 7, 7, 7},
        {2, 1, 2, 1, 2, 1},
        {5, 3, 8, 3, 9, 1, 5},
        {-5, -1, -10, 3, 2, 0},
        {-3, -2, -1, 0, 1, 2},
        {INT_MAX, INT_MIN, 0, 1, -1},
        {10, -10, 10, -10, 0},
        {9, 1, 8, 2, 7, 3, 6, 4, 5},
        {100, 90, 80, 70, 60, 50, 40},
        {4, 5, 3, 2, 1, 6},
        {1, 1, 2, 2, 3, 3, 2, 1},
        {0, 0, 0, -1, -1, 5, 5},
        {12, 4, 5, 3, 8, 7}
    };

    int tc = 1;
    int passed = 0;
    for (auto original : tests) {
        vector<int> arr = original;

        // ==========================
        // Call your sorting algorithm
        // ==========================
        mergeSort(arr.size(), arr);
        // Examples:
        // bubbleSort(arr.size(), arr);
        // insertionSort(arr.size(), arr);
        // selectionSort(arr.size(), arr);
        // if (!arr.empty()) mergeSort(arr, 0, arr.size() - 1);

        // ==========================
        // Verify
        // ==========================
        vector<int> expected = original;
        sort(expected.begin(), expected.end());
        
        if (arr == expected) {
            passed++;
            cout << "Test #" << tc << " Passed\n";
        } else {
            cout << "Test #" << tc << " FAILED\n\n";

            cout << "Original : ";
            for (int x : original) cout << x << " ";
            cout << "\n";

            cout << "Expected : ";
            for (int x : expected) cout << x << " ";
            cout << "\n";

            cout << "Got      : ";
            for (int x : arr) cout << x << " ";
            cout << "\n";
        }

        tc++;
    }
    
    cout << "Passed: " << passed <<endl;

    return 0;
}