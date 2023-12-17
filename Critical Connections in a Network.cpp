class Solution {
public:
    void dfs(int currentNode, int parentNode, vector<int> adjList[], vector<int>& visited, vector<int>& discoveryTime, vector<int>& lowTime, vector<int>& parent, int& time, vector<vector<int>>& criticalConnections) {
        // Mark the current node as visited and set the discovery time and low time
        visited[currentNode] = 1;
        discoveryTime[currentNode] = lowTime[currentNode] = time;
        parent[currentNode]=parentNode;
        time++;

        // Iterate through the adjacent nodes of the current node
        for (auto adjacentNode : adjList[currentNode]) {
            // If the adjacent node is the parent of the current node, skip it
            if (adjacentNode == parent[currentNode])
                continue;

            // If the adjacent node is not visited, recursively call dfs on it
            if (!visited[adjacentNode]) {
                dfs(adjacentNode, currentNode, adjList, visited, discoveryTime, lowTime, parent, time, criticalConnections);

                // Update the low time of the current node
                lowTime[currentNode] = min(lowTime[currentNode], lowTime[adjacentNode]);

                // If the low time of the adjacent node is greater than the discovery time of the current node,
                // it means the edge between the current node and the adjacent node is a critical connection
                if (lowTime[adjacentNode] > discoveryTime[currentNode]) {
                    criticalConnections.push_back({currentNode, adjacentNode});
                }
            }
            // If the adjacent node is already visited, update the low time of the current node
            else {
                lowTime[currentNode] = min(lowTime[currentNode], discoveryTime[adjacentNode]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Create an adjacency list to represent the connections between servers
        vector<int> adjList[n];
        for (auto connection : connections) {
            int server1 = connection[0];
            int server2 = connection[1];
            adjList[server1].push_back(server2);
            adjList[server2].push_back(server1);
        }

        vector<int> visited(n, 0);
        vector<int> discoveryTime(n, 0);
        vector<int> lowTime(n, 0);
        vector<int> parent(n, -1);
        vector<vector<int>> criticalConnections;

        int time = 0; // Variable to keep track of discovery time

        // Perform depth-first search (DFS) to find critical connections
        dfs(0, -1, adjList, visited, discoveryTime, lowTime, parent, time, criticalConnections);

        return criticalConnections;
    }
};
