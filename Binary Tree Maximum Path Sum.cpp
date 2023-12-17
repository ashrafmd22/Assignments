/*Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

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
    int help(TreeNode* root,int& ans){
        if(root==NULL) return 0;
        int left=help(root->left,ans);
        int right=help(root->right,ans);
        int maxstraight=max(max(left,right)+root->val,root->val);
        int case2=max(maxstraight,left+right+root->val);
        ans=max(ans,case2);
        return maxstraight;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
         help(root,ans);
        
        return ans;
    }
};