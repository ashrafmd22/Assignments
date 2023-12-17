#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* multiply(Node* l1, Node* l2) {
    int num1 = 0, num2 = 0;

    while (l1 || l2) {
        if (l1) {
            num1 = num1 * 10 + l1->data;
            l1 = l1->next;
        }
        if (l2) {
            num2 = num2 * 10 + l2->data;
            l2 = l2->next;
        }
    }

    int result = num1 * num2;

    Node* dummy = new Node(0);
    Node* current = dummy;

    while (result > 0) {
        int digit = result % 10;
        current->next = new Node(digit);
        current = current->next;
        result /= 10;
    }

    return dummy->next;
}
