/*Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character*/
class Solution {
public:
    int help(int i,string a,int j, string b, vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j]=help(i-1,a,j-1,b,dp);
        else{
            return dp[i][j]= 1+min(help(i,a,j-1,b,dp),min(help(i-1,a,j,b,dp),help(i-1,a,j-1,b,dp)));
        }
    }
    int minDistance(string a, string b) {
        int n=a.size();
        int m=b.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return help(n-1,a,m-1,b,dp);
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        // for(int i=0;i<=n;i++) rev[0]=i;
        for(int j=0;j<=m;j++) prev[j]=j;
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]) curr[j]=prev[j-1];
                else{
                    curr[j]=1+min(curr[j-1],min(prev[j],prev[j-1]));
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};