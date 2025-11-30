#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(NULL) {}
};

bool hasCycle(Node* head) {
    unordered_set<Node*> s;
    Node* cur = head;
    while (cur) {
        if (s.count(cur)) return true;
        s.insert(cur);
        cur = cur->next;
    }
    return false;
}

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b; 

    if (hasCycle(a)) cout << "true";
    else cout << "false";
}

