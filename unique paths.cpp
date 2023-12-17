/*Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.*/

class Solution {
public:
    int help(int r, int c,vector<vector<int>>& dp){
        if(r==0 and c==0) return 1;
        if(r<0 or c<0) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int up=help(r-1,c,dp);
        int left =help(r,c-1,dp);
        return dp[r][c]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // return help(m-1,n-1,dp);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 and j==0){ dp[i][j]=1;
                continue;}
                int up=0,left=0;
                if(i-1>=0) up=dp[i-1][j];
                if(j-1>=0) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
    }
};