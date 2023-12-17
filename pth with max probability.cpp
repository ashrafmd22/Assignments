/*Path with Maximum Probability

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back(make_pair(v, prob));
            graph[v].push_back(make_pair(u, prob));
        }
        
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;
        
        priority_queue<pair<double, int>> pq;
        pq.push(make_pair(1.0, start));
        while (!pq.empty()) {
            pair<double, int> curr = pq.top();
            pq.pop();
            double currProb = curr.first;
            int currNode = curr.second;
            
            if (currNode == end) {
                return currProb;
            }
            
            for (pair<int, double> path : graph[currNode]) {
                int nextNode = path.first;
                double nextProb = currProb * path.second;
                
                if (nextProb > maxProb[nextNode]) {
                    maxProb[nextNode] = nextProb;
                    pq.push(make_pair(nextProb, nextNode));
                }
            }
        }
        
        return 0.0;
    }
};