/*Course Schedule IV

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.*/


class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>> adj(n);
        for (const auto& it : pre) {
            adj[it[0]].push_back(it[1]); // Reverse the dependency direction
        }
        
        vector<vector<int>> reachable(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            vector<int> vis(n, 0);
            dfs(i, i, adj, reachable, vis);
        }
        
        vector<bool> ans;
        for (const auto& it : q) {
            int x = it[0];
            int y = it[1];
            ans.push_back(reachable[x][y]);
        }
        
        return ans;
    }
    
private:
    void dfs(int start, int node, const vector<vector<int>>& adj, vector<vector<int>>& reachable, vector<int>& vis) {
        vis[node] = 1;
        reachable[start][node] = 1;
        for (int nxt : adj[node]) {
            if (!vis[nxt]) {
                dfs(start, nxt, adj, reachable, vis);
            }
            for (int i = 0; i < reachable[nxt].size(); ++i) {
                reachable[start][i] |= reachable[nxt][i];
            }
        }
    }
};