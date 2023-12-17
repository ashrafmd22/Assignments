/*Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.*/

class Solution {
public:
    int help(string a, int i,string b,int j){
        if(i<0 or j<0) return 0;
        int ans=0;
        if(a[i]==b[j]) {
            ans=1+help(a,i-1,b,j-1);
        }
        else{
            ans=max(help(a,i-1,b,j),help(a,i,b,j-1));
        }
        return ans;
    }
    int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        // return help(a,n-1,b,m-1);
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};