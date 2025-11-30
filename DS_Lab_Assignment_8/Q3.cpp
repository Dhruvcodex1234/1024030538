#include <iostream>
#include <algorithm>
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

Node* minNode(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int x) {
    if (!root) return root;
    if (x < root->data) root->left = deleteNode(root->left, x);
    else if (x > root->data) root->right = deleteNode(root->right, x);
    else {
        if (!root->left) return root->right;
        else if (!root->right) return root->left;
        Node* t = minNode(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (!root) return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (!l || !r) return 1 + max(l, r);
    return 1 + min(l, r);
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 40);
    insertNode(root, 20);
    insertNode(root, 60);
    insertNode(root, 10);
    insertNode(root, 30);

    root = deleteNode(root, 20);

    cout << maxDepth(root) << endl;
    cout << minDepth(root) << endl;
}

