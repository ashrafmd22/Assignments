/*Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.*/


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
  /*  int height(TreeNode* root){
        if(root==NULL) return 0;
        
        return max(height(root->left),height(root->right))+1;
    }*/
    pair<int,int> help(TreeNode* root){
        if(root==NULL) return {0,0};
        pair<int,int> leftBT=help(root->left);
        pair<int,int> rightBT=help(root->right);
        int lh=leftBT.first;
        int ld=leftBT.second;
         int rh=rightBT.first;
        int rd=rightBT.second;
        pair<int,int> ans;
        ans.first=max(lh,rh)+1;
        ans.second=max(lh+rh,max(ld,rd));
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
       pair<int,int> ans=help(root);
        return ans.second;
    }
};