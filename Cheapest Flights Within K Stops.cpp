class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,1e9);
        dist[src]=0;
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});

        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        while(!q.empty()){
        auto fst=q.front();
        q.pop();
        int stops=fst.first;
        int node=fst.second.first;
        int cost=fst.second.second;
        if(stops>k) continue;
        for(auto itr:adj[node]){
            int adjnode=itr.first;
            int edgewt=itr.second;
            if(cost+edgewt<dist[adjnode] and stops<=k){
                dist[adjnode]=cost+edgewt;
                q.push({stops+1,{adjnode,cost+edgewt}});
            }
        }
        }

       if(dist[dst]==1e9) return -1;
        else return dist[dst];
    }
};