/*Number of Ways to Wear Different Hats to Each Other

There are n people and 40 types of hats labeled from 1 to 40.

Given a 2D integer array hats, where hats[i] is a list of all hats preferred by the ith person.

Return the number of ways that the n people wear different hats to each other.

Since the answer may be too large, return it modulo 109 + 7.*/

class Solution {
public:
vector<vector<int>>dp;
int mod=1e9+7;
    int f(int hat, int mask, int n,vector<vector<int>>& hats){
        if(mask==0) return 1;
        if(hat>40) return 0;
        if(dp[hat][mask]!=-1) return dp[hat][mask];
        int ans=f(hat+1,mask,n,hats);
        for(int i=0; i<n; i++){
            if(mask&(1<<i))
            for(int j=0; j<hats[i].size(); j++){
                if(hats[i][j]==hat ){
                    ans=(ans+f(hat+1,mask^(1<<i),n,hats))%mod;
                }
            }
        }
        return dp[hat][mask]=ans%mod;
    }
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        int mask=(1<<n)-1;
        dp.resize(42,vector<int>(mask+1,-1));
        return f(1,mask,n,hats);
    }
};