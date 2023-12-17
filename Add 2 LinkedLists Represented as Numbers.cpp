#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* addLists(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* current = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry;
        carry = sum / 10;

        current->next = new Node(sum % 10);
        current = current->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return dummy->next;
}
