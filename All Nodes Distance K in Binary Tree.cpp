/*All Nodes Distance K in Binary Tree

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> mp;
    void inorder(TreeNode* root){
        if(root==NULL) return ;
        mp[root->left]=root;
        inorder(root->left);
        mp[root->right]=root;
        inorder(root->right);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        inorder(root);
        queue<TreeNode*> qu;
        qu.push(target);
        unordered_set<int> vis;
        vis.insert(target->val);
        vector<int> ans;
        while(!qu.empty()){
            int n=qu.size();
            
            for(int i=0;i<n;i++){
                auto it=qu.front();
                qu.pop();
                if(k==0) ans.push_back(it->val);
                if(it->left and !vis.count(it->left->val)){
                    qu.push(it->left);
                        vis.insert(it->left->val);
                }
                if(it->right and !vis.count(it->right->val)){
                    qu.push(it->right);
                        vis.insert(it->right->val);
                }
                if(mp[it] and !vis.count(mp[it]->val)){
                    qu.push(mp[it]);
                        vis.insert(mp[it]->val);
                }
            }
            k--;
        }
        return ans;
    }
};