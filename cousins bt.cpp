/*Cousins in Binary Tree

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1*/

class Solution {
public:
    

    bool isCousins(TreeNode* root, int x, int y) {
        int i,j,k,c=0;
        int d1,d2;
        TreeNode* p1=NULL;TreeNode*p2=NULL;
        queue<TreeNode*>q;
        vector<int>ans;

        if(!root)
        return 0;
        q.push(root);

        while(!q.empty()){
            int levelsize=q.size();

            while(levelsize-->0){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left){
                    if(curr->left->val==x)
                    p1=curr;
                    
                    if(curr->left->val==y)
                        p2=curr;
                     
                    q.push(curr->left);
                }

                if(curr->right){
                    if(curr->right->val==x)
                    p1=curr;
                    
                    if(curr->right->val==y)
                        p2=curr;
                     
                    q.push(curr->right);
                }

                if(p1!=NULL and p2!=NULL){
                    if(p1!=p2)
                    return 1;
                    }
            }
            p1=NULL;
            p2=NULL;
            
            
        }

        
        return 0;
    }
};      