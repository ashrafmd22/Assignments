/*Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> temp;
        if(root==NULL) return ans;
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f==NULL){
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(NULL);
            }
            else{
                temp.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        for(int i=1;i<ans.size();i=i+2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};