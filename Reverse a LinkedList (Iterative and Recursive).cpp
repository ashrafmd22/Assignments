#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

Node* reverseRecursive(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* restReversed = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return restReversed;
}
