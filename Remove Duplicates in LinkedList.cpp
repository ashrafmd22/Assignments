#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void removeDuplicates(Node* head) {
    std::unordered_set<int> seen;
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (seen.find(current->data) != seen.end()) {
            prev->next = current->next;
            delete current;
        } else {
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
}
