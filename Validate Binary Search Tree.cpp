/*Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.*/

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
    bool help(TreeNode* root,long long mi=-10000000000,long long ma=10000000000){
        if(root==NULL) return true;
         bool left=help(root->left,mi,root->val);
         bool right=help(root->right,root->val,ma);
       // bool right=help(root->right,root->val,ma);
        if(root->val>mi and root->val<ma and left and right) return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        bool ans=help(root);
        return ans;
    }
};