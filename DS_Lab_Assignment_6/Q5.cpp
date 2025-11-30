#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (!head) return true;
    Node* temp = head->next;
    while (temp && temp != head) temp = temp->next;
    return temp == head;
}

int main() {
    Node* a = new Node{10, nullptr};
    Node* b = new Node{20, nullptr};
    Node* c = new Node{30, nullptr};

    a->next = b;
    b->next = c;
    c->next = a;  // Make it circular, try c->next = nullptr to test non-circular

    if (isCircular(a)) cout << "Circular Linked List" << endl;
    else cout << "Not Circular Linked List" << endl;
}

