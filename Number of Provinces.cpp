class Solution {
public:
void dfs(int node ,vector<int> adj[],vector<int>& vis){
    vis[node]=1;
    for(auto adjNode : adj[node]){
        if(!vis[adjNode]){
            dfs(adjNode,adj,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& a) {
       int tot=a.size();
        vector<int> vis(tot,0);
        vector<int> adj[tot];
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                if(a[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
      return cnt;
    }
};