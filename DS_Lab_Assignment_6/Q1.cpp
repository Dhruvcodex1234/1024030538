#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insertFirst(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    if (!head) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }
    Node* tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = head->prev = newNode;
    head = newNode;
}

void insertLast(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    if (!head) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }
    Node* tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

void insertAfter(int key, int val) {
    if (!head) return;
    Node* temp = head;
    do {
        if (temp->data == key) {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void deleteNode(int key) {
    if (!head) return;
    Node* temp = head;
    do {
        if (temp->data == key) {
            if (temp->next == temp) {
                head = nullptr;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
            }
            delete temp;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

bool searchNode(int key) {
    if (!head) return false;
    Node* temp = head;
    do {
        if (temp->data == key) return true;
        temp = temp->next;
    } while (temp != head);
    return false;
}

void display() {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
}

int main() {
    int choice, val, key;
    while (true) {
        cout << "1. InsertFirst 2. InsertLast 3. InsertAfter 4. Delete 5. Search 6. Display 7. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> val;
                insertFirst(val);
                break;
            case 2:
                cin >> val;
                insertLast(val);
                break;
            case 3:
                cin >> key >> val;
                insertAfter(key, val);
                break;
            case 4:
                cin >> key;
                deleteNode(key);
                break;
            case 5:
                cin >> key;
                cout << (searchNode(key) ? "Found\n" : "Not Found\n");
                br

