#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insertNode(Node* root, int x) {
    if (!root) {
        Node* t = new Node();
        t->data = x;
        t->left = t->right = NULL;
        return t;
    }
    if (x < root->data) root->left = insertNode(root->left, x);
    else if (x > root->data) root->right = insertNode(root->right, x);
    return root;
}

bool searchRec(Node* root, int x) {
    if (!root) return false;
    if (root->data == x) return true;
    if (x < root->data) return searchRec(root->left, x);
    return searchRec(root->right, x);
}

bool searchNonRec(Node* root, int x) {
    while (root) {
        if (root->data == x) return true;
        else if (x < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

int maxElem(Node* root) {
    while (root->right) root = root->right;
    return root->data;
}

int minElem(Node* root) {
    while (root->left) root = root->left;
    return root->data;
}

Node* minNode(Node* p) {
    while (p->left) p = p->left;
    return p;
}

Node* maxNode(Node* p) {
    while (p->right) p = p->right;
    return p;
}

Node* inorderSuccessor(Node* root, int x) {
    Node* succ = NULL;
    while (root) {
        if (x < root->data) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int x) {
    Node* pred = NULL;
    while (root) {
        if (x > root->data) {
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 40);
    insertNode(root, 20);
    insertNode(root, 60);
    insertNode(root, 10);
    insertNode(root, 30);

    cout << searchRec(root, 30) << endl;
    cout << searchNonRec(root, 60) << endl;
    cout << maxElem(root) << endl;
    cout << minElem(root) << endl;

    Node* s = inorderSuccessor(root, 30);
    Node* p = inorderPredecessor(root, 30);
    if (s) cout << s->data << endl;
    if (p) cout << p->data << endl;
}

