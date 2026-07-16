#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class List {
private:
    Node* head;
    Node* tail;
    
public:
    List() {
        head = tail = nullptr;
    }

    ~List() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next; 
            delete temp;                 
            temp = nextNode;             
        }
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void printLL() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    void pop_front() {
        if (head == nullptr) return;
        
        Node* oldHead = head;
        head = head->next;
        
        // Fix: If the list is now empty, tail must also be reset
        if (head == nullptr) {
            tail = nullptr;
        }
        
        delete oldHead;
    }

    void pop_back() {
        if (head == nullptr) return;

        // Fix: Handle single element list specifically to avoid nullptr crash
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        temp->next = nullptr;
        tail = temp;
    }

    void insert(int val, int pos) {
        if (pos < 0) return;
        if (pos == 0) {
            push_front(val);
            return;
        }
        
        Node* temp = head;

        // Traverse to the node right before the insertion point
        for (int i = 0; i < pos - 1; i++) {
            if (temp == nullptr) {
                cout << "Invalid position" << endl;
                return;
            }
            temp = temp->next;
        }
        
        // Safety check if pos is exactly one past the valid bounds
        if (temp == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(val); 
        newNode->next = temp->next;
        temp->next = newNode;

        // Fix: If we just inserted at the very end, update the tail pointer
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    int search(int val) {
        Node* temp = head;
        int idx = 0;
        while (temp != nullptr) {
            if (temp->data == val) return idx;
            temp = temp->next;
            idx++;
        }
        return -1;
    }
};