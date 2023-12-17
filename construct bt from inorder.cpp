/*Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.*/

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
    TreeNode* help(vector<int>& preorder,int pres,int pree ,vector<int>& inorder,int ins,int ine){
        if(ins>ine) return NULL;
        int rootdata=preorder[pres];
        int rootindex=-1;
        for(int i=ins;i<=ine;i++){
            if(inorder[i]==rootdata){
                rootindex=i;
                break;
            }
        }
        
        TreeNode* root=new TreeNode(rootdata);
        int lins=ins;
        int line=rootindex-1;
        int lpres=pres+1;
        int lpree=line-lins+lpres;
        
        int rins=rootindex+1;
        int rine=ine;
        int rpres=lpree+1;
        int rpree=pree;
        root->left=help(preorder,lpres,lpree,inorder,lins,line);
        root->right=help(preorder,rpres,rpree,inorder,rins,rine);
        return root;
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
         int m=inorder.size();
        return help(preorder,0,n-1,inorder,0,m-1);
    }
};