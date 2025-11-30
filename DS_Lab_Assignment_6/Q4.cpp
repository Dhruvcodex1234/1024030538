#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* tail = head;
    while (tail->next) tail = tail->next;
    while (head != tail && head->prev != tail) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node* a = new Node{'r', nullptr, nullptr};
    Node* b = new Node{'a', nullptr, a};
    Node* c = new Node{'d', nullptr, b};
    Node* d = new Node{'a', nullptr, c};
    Node* e = new Node{'r', nullptr, d};
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    cout << (isPalindrome(a) ? "Palindrome" : "Not Palindrome") << endl;
}

