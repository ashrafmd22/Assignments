/*Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.*/
class Solution {
public:
    int help(int i,int n,vector<int>& a,int buy,vector<vector<int>>& dp){
        if(i==n) return 0;
        int ans=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==0){
            ans=max(help(i+1,n,a,0,dp),-a[i]+help(i+1,n,a,1,dp));
        }
        
        if(buy==1){
            ans=max(help(i+1,n,a,1,dp),a[i]+help(i+1,n,a,0,dp));
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& a) {
        int n=a.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        // return help(0,n,a,0,dp);
        vector<int> ahead(2,0);
        vector<int> curr(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                if(buy==0){
                    curr[buy]=max(ahead[0],-a[i]+ahead[1]);
                }
                
                if(buy==1){
                    curr[buy]=max(ahead[1],a[i]+ahead[0]);
                }
            }
            ahead=curr;
        }
        return curr[0];
    }
};