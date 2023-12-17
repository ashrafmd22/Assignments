/* Number of Longest Increasing Subsequence

Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
         int n=a.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j] and 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }
                else if(a[i]>a[j] and dp[i]==1+dp[j]) cnt[i]+=cnt[j];
            }
        }
       
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        int no=0;
        for(int i=0;i<n;i++){
            if(dp[i]==ans) no+=cnt[i];
        }
        return no;
    }
};