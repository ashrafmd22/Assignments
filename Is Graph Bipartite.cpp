class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> node_color(graph.size(), -1);
        queue<int> ordering;
        for(int i = 0 ; i < graph.size(); i++) {
            ordering.push(i);
            if(node_color[i] >= 0) continue;
            node_color[i] = 0;
            while(!ordering.empty()) {
                int i = ordering.front(); ordering.pop();
                for(auto neighbor: graph[i]) {
                    if(node_color[neighbor] == node_color[i]) return false;
                    else if(node_color[neighbor] >= 0) continue;
                    node_color[neighbor] = !node_color[i];
                    ordering.push(neighbor);
                }
            }
        }
        return true;
    }
};