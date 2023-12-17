class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& a) {
         vector<int> adj[n];
        vector<int> indeg(n,0);
        queue<int> q;
        for(auto it : a){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans.push_back(it);
            for(auto itt : adj[it]){
                indeg[itt]--;
                if(indeg[itt]==0) q.push(itt);
            }
        }
        if(ans.size()!=n) return {};
        return ans;
    }
};