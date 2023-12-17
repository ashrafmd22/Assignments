/*Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.*/

class Solution {
public:
    int lcs(string a,int i,string b,int j){
     if(i<0 or j<0) return 0;
     if(a[i]==b[j]) return 1+lcs(a,i-1,b,j-1);
     else return max(lcs(a,i,b,j-1),lcs(a,i-1,b,j));
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        int n=s.size();
        reverse(t.begin(),t.end());
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return lcs(s,n-1,t,n-1);
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        for(int j=0;j<n;j++) prev[j]=0;
        
        for(int i=1;i<=n;i++){
            curr[0]=0;
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
     return curr[n];
    }
};