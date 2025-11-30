#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

int sizeDoubly(Node* h) {
    int count = 0;
    Node* temp = h;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int sizeCircular(Node* h) {
    if (!h) return 0;
    int count = 0;
    Node* temp = h;
    do {
        count++;
        temp = temp->next;
    } while (temp != h);
    return count;
}

int main() {
    Node* d1 = new Node{10, nullptr, nullptr};
    Node* d2 = new Node{20, nullptr, d1};
    d1->next = d2;
    head = d1;
    cout << "Doubly size: " << sizeDoubly(head) << endl;
    d2->next = d1;
    d1->prev = d2;
    cout << "Circular size: " << sizeCircular(head) << endl;
}

