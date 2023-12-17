/*Coin Change II

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.*/

class Solution {
public:
    int help(int i,vector<int> a,int tar,int n, vector<vector<int>>& dp){
        
        if(i==0){
            return tar%a[i]==0;
        }
        if(dp[i][tar]!=-1) return dp[i][tar];
        int notpick=help(i-1,a,tar,n,dp);
        int pick=0;
        if(a[i]<=tar){
            pick=help(i,a,tar-a[i],n,dp);
        }
        return dp[i][tar]=pick+notpick;
    }
    int change(int target, vector<int>& a) {
        int n=a.size();
        // vector<vector<int>> dp(n,vector<int>(target+1,-1));
        // return help(n-1,a,target,n,dp);
        vector<int> prev(target+1,0);
           vector<int> curr(target+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<=target;j++){
                if(i==0){
                    curr[j]=(j%a[i]==0);
                }
                else{
                     int notpick=prev[j];
                    int pick=0;
                    if(a[i]<=j){
                        pick=curr[j-a[i]];
                    }
                     curr[j]=pick+notpick;
                }
            }
            prev=curr;
        }
        return prev[target];
    }
};