#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isBSTUtil(Node* root, int minV, int maxV) {
    if (!root) return true;
    if (root->data <= minV || root->data >= maxV) return false;
    return isBSTUtil(root->left, minV, root->data) &&
           isBSTUtil(root->right, root->data, maxV);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -1000000, 1000000);
}

int main() {
    Node* a = new Node{40, NULL, NULL};
    a->left = new Node{20, NULL, NULL};
    a->right = new Node{60, NULL, NULL};

    cout << isBST(a);
}

