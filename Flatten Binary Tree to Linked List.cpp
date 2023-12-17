/*Flatten Binary Tree to Linked List

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        //if(root==NULL or (root->left==NULL and root->right==NULL)) return;
        if(root == nullptr) return;
        
        TreeNode* tempLeft = root->left;
        TreeNode* tempRight = root->right;
        
        root->left = nullptr;
        
        flatten(tempLeft);
        flatten(tempRight);
        
        root->right = tempLeft;
        TreeNode* current = root;
        while(current->right != nullptr) current = current->right;
        current->right = tempRight;
    }
};