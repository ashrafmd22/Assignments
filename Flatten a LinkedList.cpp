#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* down;
    Node(int val) : data(val), next(nullptr), down(nullptr) {}
};

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;

    if (a->data < b->data) {
        result = a;
        result->down = merge(a->down, b);
    } else {
        result = b;
        result->down = merge(a, b->down);
    }

    return result;
}

Node* flatten(Node* root) {
    if (!root || !root->next) {
        return root;
    }

    return merge(root, flatten(root->next));
}
