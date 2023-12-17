#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    std::unordered_set<Node*> visited;
    Node* current = head;

    while (current != nullptr) {
        if (visited.find(current) != visited.end()) {
            return true;  // Cycle detected
        }

        visited.insert(current);
        current = current->next;
    }

    return false;  // No cycle
}
