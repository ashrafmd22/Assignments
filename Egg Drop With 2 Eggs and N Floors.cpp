/*Egg Drop With 2 Eggs and N Floors

You are given two identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

In each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.*/

class Solution {
public:
     int solve(int k, int n, int dp[3][1001])
    {
        if(k==1 || n==0 || n==1)
        return n;
        if(dp[k][n] != -1)
        return dp[k][n];
        int mn = INT_MAX, low, high;
        for(int k1=1; k1<=n; k1++)
        {
            if(dp[k-1][k1-1] != -1)
            low = dp[k-1][k1-1];
            else
            {
                low = solve(k-1, k1-1, dp);
                dp[k-1][k1-1] = low;
            }
            if(dp[k][n-k1] != -1)
            high = dp[k][n-k1];
            else
            {
                high = solve(k, n-k1, dp);
                dp[k][n-k1] = high;
            }
            int temp = 1 + max(low, high);
            mn = min(mn, temp);
        }
        return dp[k][n] = mn;
    }
    int twoEggDrop(int n) {
        int dp[3][1001];
        memset(dp, -1, sizeof(dp));
        return solve(2, n, dp);
    }
};