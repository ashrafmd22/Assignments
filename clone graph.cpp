/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*, Node*> mp;
        Node* root= new Node(node->val);
        mp[node]=root;
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            Node* copynode=mp[node];
            for(auto it  : node->neighbors){
                if(mp.count(it)){
                    copynode->neighbors.push_back(mp[it]);
                }
                else{
                    Node* cop = new Node(it->val);
                    mp[it]=cop;
                    copynode->neighbors.push_back(mp[it]);
                    q.push(it);
                }
            }
        }
        return root;
    }
};