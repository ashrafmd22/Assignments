/* Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.*/
class Solution {
public:
    int help(int i,int j,vector<vector<int>> a,vector<vector<int>>& dp){
        if(i>=0 and j>=0 and a[i][j]==1) return 0;
        if(i==0 and j==0) return 1;
        if(i<0 or j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up=help(i-1,j,a,dp);
        int left=help(i,j-1,a,dp);
        return dp[i][j]= up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    if (a[0][0] == 1) {
        return 0;  // Starting position is an obstacle, no paths are possible
    }
    
    dp[0][0] = 1;  // Set the starting position to 1 since it's not an obstacle
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                dp[i][j] = 0;  // Current cell is an obstacle, no paths are possible
                continue;
            }
            
            if (i - 1 >= 0) {
                dp[i][j] += dp[i - 1][j];  // Add the number of paths from the top cell
            }
            
            if (j - 1 >= 0) {
                dp[i][j] += dp[i][j - 1];  // Add the number of paths from the left cell
            }
        }
    }
    
    return dp[n - 1][m - 1];  // Return the number of paths to the bottom-right corner
}

};