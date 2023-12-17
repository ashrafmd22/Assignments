/*Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 */
 class Solution {
public:
    void help(int open,int close,int n,string curr,vector<string>& ans){
        if(curr.size()==n*2){
            ans.push_back(curr);
            return ;
        }
        if(open<n){
             help(open+1,close,n,curr+'(',ans);
        }
        if(close<open){
             help(open,close+1,n,curr+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
      vector<string> ans;
        help(0,0,n,"",ans);
        return ans;
    }
};