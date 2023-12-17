#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* josephusCircle(Node* head, int k) {
    if (!head || k <= 0) {
        return nullptr;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current->next != current) {
        for (int i = 1; i < k; ++i) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        delete current;
        current = prev->next;
    }

    return current;
}
