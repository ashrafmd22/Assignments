/*Minimum Degree of a Connected Trio in a Graph

You are given an undirected graph. You are given an integer n which is the number of nodes in the graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.

A connected trio is a set of three nodes where there is an edge between every pair of them.

The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.

Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.

 */

 class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> degree(n + 1);
        vector<vector<int> > adj(n + 1, vector<int>(n + 1));
        for(auto &e : edges) {
            ++degree[e[0]];
            ++degree[e[1]];
            adj[e[0]][e[1]] = 1;
            adj[e[1]][e[0]] = 1;
        }
        int ans = INT_MAX;
        for(int i = 1; i <= n; ++i) {
            if(degree[i] < 2) continue;
            for(int j = i + 1; j <= n; ++j) {
                if(degree[j] < 2) continue;
                if (!adj[i][j]) continue;
                for(int k = j + 1; k <=n; ++k) {
                    if(degree[k] < 2) continue;
                    if(adj[i][j] && adj[j][k] && adj[k][i]) {
                        ans = min(ans, degree[i] - 2 + degree[j] - 2 + degree[k] - 2);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};