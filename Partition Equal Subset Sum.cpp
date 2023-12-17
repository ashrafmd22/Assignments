/*Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.*/


class Solution {
public:
    bool help(int i,int target,vector<int>& a,int n,vector<vector<int>>& dp){
        if(i==0) {
            if(target==0) return true;
            else if(target==a[0]) return true;
            else return false;
        }
        
        if(dp[i][target]!=-1) return dp[i][target];
        int pick=0;
       if(target>=a[i])
         pick =help(i-1,target-a[i],a,n,dp);
        int notpick=help(i-1,target,a,n,dp);
        return dp[i][target]=(pick or notpick);
    }
    // bool canPartition(vector<int>& a) {
    //     int tot=0;
    //     for(int i=0;i<a.size();i++) tot+=a[i];
    //     if(tot%2!=0) return false;
    //     int n=a.size();
    //     // vector<vector<int>> dp(n,vector<int>(tot/2+1,-1));
    //     // return help(n-1,tot/2,a,n,dp); 
    //     vector<int> prev(tot/2+1,-1);
    //     vector<int> curr(tot/2+1,-1);
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<=(tot/2);j++){
    //             if(i==0){
    //                 if(j==0) prev[j]=1;
    //                 else if(j==a[0]) prev[j]=1;
    //                 else prev[j]=0;
    //             }
    //             else{
    //                 int pick=0;
    //                 if(j>=a[i]){
    //                     pick=prev[j-a[i]];
    //                 }
    //                 int notpick=prev[j];
    //                 curr[j]=pick or notpick;
    //             }
    //         }
    //         prev=curr;
    //     }
    //     return prev[tot/2];
    // }
    bool canPartition(vector<int>& a) {
    int tot = 0;
    for (int i = 0; i < a.size(); i++) {
        tot += a[i];
    }
    
    if (tot % 2 != 0) {
        return false;
    }
    
    int n = a.size();
    vector<int> prev(tot/2 + 1, -1);
    vector<int> curr(tot/2 + 1, -1);
    
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j <= tot/2; j++) {
            if (i == 0) {
                if (j == 0 || j == a[0]) {
                    curr[j] = 1;
                } else {
                    curr[j] = 0;
                }
            } else {
                int pick = 0;
                if (j >= a[i]) {
                    pick = prev[j - a[i]];
                }
                int notpick = prev[j];
                curr[j] = pick || notpick;
            }
        }
        prev = curr;
    }
    
    return prev[tot/2];
}

};