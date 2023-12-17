/*Symmetric Tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).*/

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
    bool sym(TreeNode* a,TreeNode* b){
        if(a==NULL and b==NULL) return true;
        else if(a==NULL and b!=NULL) return false;
        else if(a!=NULL and b==NULL) return false;
        else if(a->val!=b->val) return false;
        return sym(a->left,b->right) and sym(a->right,b->left);
    }
    bool isSymmetric(TreeNode* a) {
        if(a==NULL) return true;
        return sym(a->left,a->right);
    }
};