class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> topo;
        vector<int> adj[n];
        for(auto it:a){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> in(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                in[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node =q.front();
            topo.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                in[it]--;
                if(in[it]==0)q.push(it);
            }
        }
        return topo.size()==n;
    }
};