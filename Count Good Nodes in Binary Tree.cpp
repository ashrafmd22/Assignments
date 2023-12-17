/*Count Good Nodes in Binary Tree

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 */

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
    void help(TreeNode* root,int& ans,int prev){
        if(root==NULL) return;
        if(root->val>=prev) {
            ans++;
            prev=root->val;}
        help(root->left,ans,prev);
        help(root->right,ans,prev);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        help(root,ans,root->val);
        return ans;
    }
};