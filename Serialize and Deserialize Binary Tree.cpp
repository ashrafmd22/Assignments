/* Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    // A marshalled form which is unique for every tree needs to be implemented
    // level order traversal appears to do the same, where we send in spec chars to denote NULL

private:
    int resolveStringToNodeVal(string token) {
        int absVal = stoi(token);
        if(absVal > 1000) {
            absVal -= 1000;
            absVal *= -1;
        }
        return absVal;
    } 

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string data = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front();
            if(node) {
                int val = abs(node->val);
                if(node->val < 0) {
                    val += 1000; // off-setting
                }
                data += to_string(val);
            }
            else data += "#";

            data += ' '; // delimiter for seperation of numbers(more than 1 digits and neg) while unmarshalling

            q.pop();

            if(node == nullptr) continue;

            q.push(node->left);
            q.push(node->right);    
        }

        for(auto c : data) cout << c;

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;

        stringstream ss(data);
        string token;

        ss >> token;
        int absVal = resolveStringToNodeVal(token);
        
        TreeNode* root = new TreeNode(absVal);

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty() and (ss >> token)) {

            auto node = q.front();
            q.pop();

            if(token == "#") {
                node->left = nullptr;
            }
            else {
                int absVal = resolveStringToNodeVal(token);
                node->left = new TreeNode(absVal);
                q.push(node->left);
            }

            ss >> token; 

            if(token == "#") {
                node->right = nullptr;
            }
            else {
                int absVal = resolveStringToNodeVal(token);
                node->right = new TreeNode(absVal);
                q.push(node->right);
            }
        }

        return root;
    }
};

