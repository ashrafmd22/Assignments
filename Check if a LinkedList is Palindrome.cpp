#include <iostream>
#include <stack>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool isPalindrome(Node* head) {
    std::stack<int> st;
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        st.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the length of the list is odd, skip the middle element
    if (fast != nullptr) {
        slow = slow->next;
    }

    while (slow != nullptr) {
        if (slow->data != st.top()) {
            return false;
        }
        st.pop();
        slow = slow->next;
    }

    return true;
}
