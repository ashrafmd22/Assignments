/*Target Sum

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.*/

class Solution {
public:
    int help(int i,vector<int>& a,int tar,vector<vector<int>>& dp){
        if(i==0){
            if(tar==0 and a[0]==0) return 2;
            else if(tar==0 or a[0]==tar) return 1;
            else return 0;
        }
        if(dp[i][tar]!=-1) return dp[i][tar];
        int notpick=help(i-1,a,tar,dp);
        int pick=0;
        if(a[i]<=tar){
            pick=help(i-1,a,tar-a[i],dp);
        }
        return dp[i][tar]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& a, int target) {
        int tot=0;
        for(int i=0;i<a.size();i++) tot+=a[i];
        int n=a.size();
        if((tot-target)%2!=0 or tot-target<0) return 0;
        int k=(tot-target)/2;
        // vector<vector<int>> dp(n,vector<int>(k+1,-1));
        vector<int> prev(k+1,0);
        vector<int> curr(k+1,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                if(i==0){
                    if(j==0 and a[0]==0) curr[j]=2;
                    else if(j==0 or a[0]==j) curr[j]=1;
                    else curr[j]=0;
                }
                else {
                    int notpick=prev[j];
                    int pick=0;
                    if(a[i]<=j){
                    pick=prev[j-a[i]];
                     }
                   curr[j]=pick+notpick;
                }
            }
            prev=curr;
        }
        return prev[k];
    }
};