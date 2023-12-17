/*Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.*/

class Solution {
public:
    int help(int i,vector<int>& a,int tar,int n,vector<vector<int>>& dp){
        if(i==0){
            if(tar%a[i]==0) return tar/a[i];
            else return 1e9;
        }
        if(dp[i][tar]!=-1) return dp[i][tar];
        int notpick=help(i-1,a,tar,n,dp);
        int pick=1e9;
        if(a[i]<=tar){
            pick=1+help(i,a,tar-a[i],n,dp);
        }
        return dp[i][tar]=min(pick,notpick);
    }
    int coinChange(vector<int>& a, int target) {
        int n=a.size();
        // vector<vector<int>> dp(n,vector<int>(target+1,-1));
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
       
        for(int i=0;i<n;i++){
            for(int j=0;j<=target;j++){
                if(i==0){
                     if(j%a[0]==0) curr[j]=j/a[0];
                     else curr[j]=1e9;
                }
                else {
                    int notpick=prev[j];
                    int pick=1e9;
                    if(a[i]<=j){
                        pick=1+curr[j-a[i]];
                    }
                    curr[j]=min(pick,notpick);
                }
            }
            prev=curr;
        }
        if(prev[target]>=1e9) return -1;
        return prev[target];
    }
};