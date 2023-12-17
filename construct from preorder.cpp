/*Construct Binary Search Tree from Preorder Traversal

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.*/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    vector<int>inorder, v;
    v=preorder;
    sort(v.begin(), v.end());
    inorder=v;
    if(preorder.size()==0){return NULL;}
    map<int, int>m;
    for(int i=0; i<inorder.size(); i++){
        m[inorder[i]]=i;
    }
    TreeNode* root=formtree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, m);
    return root;
}
TreeNode* formtree(vector<int>& preorder, int pst, int pen, vector<int>& inorder, int inst, int inen, map<int, int>& m){
    if(pst>pen || inst>inen){return NULL;}
    TreeNode* root=new TreeNode(preorder[pst]);
    int pos=m[preorder[pst]];
    int lft=pos-inst;
    root->left=formtree(preorder, pst+1, pst+lft, inorder, inst, pos-1, m);
    root->right=formtree(preorder, pst+lft+1, pen, inorder, pos+1, inen, m);
    return root;
}
};