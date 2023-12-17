/*Super Egg Drop

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

 */

 class Solution {
public:
    int superEggDrop(int k, int n) {
        int dp[n+1][k+1];
        //dp[i][j] holds minimum moves for ith floor with j eggs
        for(int i=1;i<=k;i++){
            dp[0][i]=0;
            dp[1][i]=1;
        }
        for(int i=1;i<=n;i++){
            dp[i][1]=i;
            dp[i][0]=INT_MAX;
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){

                int low=1,high=i,temp=0,ans=INT_MAX;
                while(low<=high){
                    int mid=(low+high)/2;
                    int left=dp[mid-1][j-1];
                    int right=dp[i-mid][j];
                    temp=1+max(left,right);
                    if(left<right)low=mid+1;
                    else
                    high=mid-1;
                    ans=min(ans,temp);
                }
                dp[i][j]=ans;
            }
        }
        return dp[n][k];
    }
};
