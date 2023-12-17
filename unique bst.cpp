/* Unique Binary Search Trees

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 */
 class Solution {
public:
    vector<int> dp;
    int helper(int n){
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        int ans = 0;
        
        for(int i=1; i<=n; i++){
            ans = ans + helper(i-1)*helper(n-i);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        dp.resize(20,-1);
        return helper(n);
    }
};