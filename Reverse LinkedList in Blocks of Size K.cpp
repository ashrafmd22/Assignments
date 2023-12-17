#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseKGroup(Node* head, int k) {
    Node* current = head;
    Node* next = nullptr;
    Node* prev = nullptr;
    int count = 0;

    // Count the number of nodes in the current group
    Node* temp = head;
    while (temp != nullptr && count < k) {
        temp = temp->next;
        count++;
    }

    // If the group has k nodes, reverse them
    if (count == k) {
        temp = reverseKGroup(temp, k);
        while (count-- > 0) {
            next = current->next;
            current->next = temp;
            temp = current;
            current = next;
        }
        head = temp;
    }

    return head;
}
