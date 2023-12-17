/* Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.*/
class Solution {
public:
int help(int i,int j,vector<vector<int>> a,vector<vector<int>>& dp){
    if(i==0 and j==0) return a[0][0];
    if(i<0 or j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=a[i][j]+help(i-1,j,a,dp);
    int left=a[i][j]+help(i,j-1,a,dp);
    return dp[i][j]=min(left,up);
}
    int minPathSum(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        // return help(n-1,m-1,a,dp);
        dp[0][0] = a[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0) dp[i][j]=a[i][j];
                else{
                    // dp[i][j]=a[i][j];
                    int left=0,up=0;
                    if(j>0){
                      left=a[i][j]+dp[i][j-1];
                    }
                    else left=1e9;
                    if(i>0){
                        up=a[i][j]+dp[i-1][j];
                    }
                    else up=1e9;
                    dp[i][j]=min(left,up);
                }
            }
        }
        return dp[n-1][m-1];
    }
};