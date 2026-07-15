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

    void push_front(int val) {
        Node* newNode = new Node(val);
        if( head == nullptr ) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    
    void push_back(int val) {
        Node* newNode = new Node(val);
        if( head == nullptr ) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void printLL() {
        Node* temp = head;
        while( temp != nullptr ) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void pop_front() {
        if(head == nullptr) return;
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
    }

    void pop_back() {
        if(head == nullptr) return;

        Node* temp = head;

        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
        
    }
};