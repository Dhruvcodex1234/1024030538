#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* getNode(int x) {
    Node* t = new Node();
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = getNode(10);
    root->left = getNode(5);
    root->right = getNode(20);
    root->left->left = getNode(2);
    root->left->right = getNode(7);

    preorder(root); cout << endl;
    inorder(root); cout << endl;
    postorder(root);
}

