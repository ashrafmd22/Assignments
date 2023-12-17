class DisjointSet {
public:
    vector<int> parent, size, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = findParent(parent[n]);
    }

    void unionByRank(int u, int v) {
        int ul = findParent(u);
        int vl = findParent(v);
        if (rank[ul] == rank[vl]) {
            parent[ul] = vl;
            rank[vl]++;
        } else if (rank[ul] > rank[vl]) {
            parent[vl] = ul;
        } else {
            parent[ul] = vl;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DisjointSet ds(n);

        // Calculate distances and sort points based on distance
        vector<pair<int, pair<int, int>>> distances;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                distances.push_back({distance, {i, j}});
            }
        }
        sort(distances.begin(), distances.end());

        int minCost = 0;
        for (auto dist : distances) {
            int u = dist.second.first;
            int v = dist.second.second;
            int parentU = ds.findParent(u);
            int parentV = ds.findParent(v);

            if (parentU != parentV) {
                ds.unionByRank(parentU, parentV);
                minCost += dist.first;
            }
        }

        return minCost;
    }
};
