#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;   // heap[0] is dummy
    // this is the max index we can access
    int sz;

    // Time: O(log N)
    void heapifyUp(int idx) {
       while(idx > 1 && heap[idx] > heap[idx/2]) {
            swap(heap[idx], heap[idx/2]);
            idx /= 2;
       }
    }

    // Time: O(log N)
    void heapifyDown(int idx) {
        while (2*idx <= sz) {
            int left = 2 * idx;
            int right = 2 * idx + 1;
            int largest = idx;

            if(heap[left] > heap[largest]) largest = left;
            if(right <= sz && heap[right] > heap[largest]) largest = right;

            if(largest == idx) return;

            swap(heap[idx], heap[largest]);
            idx = largest;
        }
        
    }

public:
    MaxHeap() {
        heap.push_back(-1);
        sz = 0;
    }

    MaxHeap(const vector<int>& arr) {
        heap.push_back(-1);
        sz = 0;

        for (int x : arr) {
            heap.push_back(x);
            sz++;
        }

        buildHeap();
    }

    bool isEmpty() const {
        return sz == 0;
    }

    int size() const {
        return sz;
    }

    int top() const {
        if (isEmpty()) return -1;
        return heap[1];
    }

    // Time: O(log N)
    void push(int val) {
        heap.push_back(val);
        sz++;
        heapifyUp(sz);
    }
    // Time: O(log N)
    int pop() {
        if(isEmpty()) return -1;
        int root = heap[1];
        swap(heap[1], heap[sz]);
        heap.pop_back();
        sz--;

        heapifyDown(1);
        return root;
    }
    // Time complexity is O(N) if we have the array already
    // if we are pushing each element and doing heapify up it would have been nlogn
    // Time: O(N) 
    // Study this buildHeap again IMPPPP
    // n/2 + 1 .. n is leaves 
    // we are starting to build the tree from a level just above the leaves. Kind of bottom up
    void buildHeap() {
        for(int i = sz/2; i >= 1; i--) {
            heapifyDown(i);
        }
    }

    void print() const {
        for (int i = 1; i <= sz; i++)
            cout << heap[i] << " ";
        cout << '\n';
    }

    // O(N logN)
    // the largest element keeps taking its place in the last of the array
    // finally restore the original size
    void heapSort() {
        int originalSize = sz;

        while (sz > 0) {
            swap(heap[1], heap[sz]);
            sz--;
            heapifyDown(1);
        }

        sz = originalSize;
    }

    bool validateHeap() const {
        int n = heap.size() - 1;
    
        for (int i = 1; i <= n / 2; i++) {
            int left = 2 * i;
            int right = 2 * i + 1;
    
            if (left <= n && heap[i] < heap[left])
                return false;
    
            if (right <= n && heap[i] < heap[right])
                return false;
        }
    
        return true;
    }
};

int main() {
    MaxHeap h;

    vector<int> inserted;

    auto verify = [&](const string &msg) {
        cout << msg << " : ";

        if (!h.validateHeap()) {
            cout << "FAILED\n";
            cout << "Heap contents: ";
            h.print();
            exit(0);
        }

        vector<int> expected = inserted;
        sort(expected.begin(), expected.end(), greater<int>());

        if (expected.empty()) {
            if (!h.isEmpty() || h.size() != 0 || h.top() != -1) {
                cout << "FAILED\n";
                cout << "Expected an empty heap.\n";
                exit(0);
            }
        } else {
            if (h.top() != expected[0]) {
                cout << "FAILED\n";
                cout << "Expected top = " << expected[0]
                     << ", Got = " << h.top() << endl;
                exit(0);
            }

            if (h.size() != expected.size()) {
                cout << "FAILED\n";
                cout << "Expected size = " << expected.size()
                     << ", Got = " << h.size() << endl;
                exit(0);
            }
        }

        cout << "PASSED\n";
    };

    // ===========================
    // Initial State
    // ===========================

    verify("Initial heap");

    // ===========================
    // Insertions
    // ===========================

    vector<int> nums = {
        10, 5, 30, 2, 20, 40, 15, 50,
        8, 60, 1, 35, 45, 45, 100
    };

    for (int x : nums) {
        h.push(x);
        inserted.push_back(x);

        verify("Push " + to_string(x));
    }

    // ===========================
    // Pop everything
    // ===========================

    sort(inserted.begin(), inserted.end(), greater<int>());

    cout << "\nChecking Pop Order...\n";

    while (!inserted.empty()) {
        int expected = inserted.front();

        int got = h.pop();

        if (got != expected) {
            cout << "FAILED\n";
            cout << "Expected pop = " << expected
                 << ", Got = " << got << endl;
            return 0;
        }

        inserted.erase(inserted.begin());

        verify("After pop");
    }

    // ===========================
    // Pop from empty heap
    // ===========================

    if (h.pop() != -1) {
        cout << "FAILED\n";
        cout << "Pop on empty heap should return -1\n";
        return 0;
    }

    verify("After popping everything");

    // ===========================
    // Reuse heap
    // ===========================

    h.push(200);
    inserted.push_back(200);
    verify("Push 200");

    h.push(150);
    inserted.push_back(150);
    verify("Push 150");

    h.push(250);
    inserted.push_back(250);
    verify("Push 250");

    cout << "\nFinal Heap: ";
    h.print();

    cout << "\nAll Test Cases Passed!\n";

    h.heapSort();
    h.print();

    return 0;
}