/*All Paths From Source to Target

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).*/

class Solution {
public:
    
    void dfs(vector<vector<int>> &res, int start,vector<vector<int>> &g, vector<int> &v )
    {
        v.push_back(start);
        if(start == g.size()-1)
        {
            res.push_back(v);
        }
        else{
            for(auto i : g[start])
            {
                dfs(res,i,g,v);
            }
        }
        
        v.pop_back();
        
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
         vector<vector<int>> res;
         vector<int> v;
        dfs(res,0,g,v);
        
        return res;
        
    }
};