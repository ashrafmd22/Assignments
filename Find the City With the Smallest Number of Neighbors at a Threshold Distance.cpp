/* Find the City With the Smallest Number of Neighbors at a Threshold Distance

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.*/

class Solution {
public:
unordered_map<int,int>m;
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        int ind=-1,ans=1e8;
       for(int i=0;i<n;i++)
       {
           queue<pair<int,int>>q;
           q.push({i,0});
           vector<int>dis(n,1e8);
           dis[i]=0;
           while(!q.empty())
           {
               int node=q.front().first;
               int wt=q.front().second;
               q.pop();
               for(auto x:adj[node])
               {
                   int node1=x.first;
                   int wt1=x.second;
                   if(wt+wt1<dis[node1])
                   {
                       dis[node1]=wt+wt1;
                       q.push({node1,wt+wt1});
                   }
               }
           }
           int c=0;
           for(int i=0;i<dis.size();i++)
           {
               if(dis[i]<=threshold)
               {
                   c++;
               }
           }
           if(c<=ans)
           {
               ans=c;
               ind=max(ind,i);
           }
           
       }
       return ind;


    }
};