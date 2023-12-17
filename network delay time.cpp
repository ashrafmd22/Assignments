/*Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.*/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto vec: times){
            adj[vec[0]].push_back({vec[1], vec[2]});
        }
        vector<int> time(n+1, INT_MAX);
        time[k] = 0;
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            int currTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(currTime > time[node]) continue;

            for(auto it: adj[node]){
                int next = it.first;
                int timetaken = it.second;
                if(currTime + timetaken < time[next]){
                    pq.push({currTime + timetaken, next});
                    time[next] = currTime + timetaken;
                }
            }
        }
        int answer = INT_MIN;
        for(int i = 1; i <= n; i++){
            answer = max(answer, time[i]);
        }
        return (answer != INT_MAX) ? answer : -1;
    }
};