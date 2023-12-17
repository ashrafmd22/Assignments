/*Two City Scheduling

A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [&](vector<int>& a, vector<int>& b){
            int diff1 = abs(a[0] - a[1]);
            int diff2 = abs(b[0] - b[1]);
            return diff1 > diff2;
        });
        int n = costs.size();
        int a = n / 2, b = n / 2;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            vector<int> cost = costs[i];

            if(cost[0] < cost[1] && a > 0) {
                ans += cost[0]; a--;
            } 
            else if(cost[0] > cost[1] && b > 0) {
                ans += cost[1]; b--;
            }
            else if(b > 0) {
                ans += cost[1]; b--;
            } 
            else {
                ans += cost[0]; a--;
            }

        }

        return ans;
    }
};