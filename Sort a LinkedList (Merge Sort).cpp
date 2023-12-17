#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->data < right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* right = mergeSort(slow->next);
    slow->next = nullptr;
    Node* left = mergeSort(head);

    return merge(left, right);
}
