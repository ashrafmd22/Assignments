/* Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.*/

class Solution {
public:
 void help(vector<int> a,int target,vector<vector<int>>& ans,int i,vector<int> o){
        if(i==a.size()){
            if(target==0){
            ans.push_back(o);}
            return;
        }
        
        if(a[i]<=target){
        o.push_back(a[i]);
        help(a,target-a[i],ans,i,o);
        o.pop_back();
        }
        help(a,target,ans,i+1,o);
    }
   
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
         vector<vector<int>> ans;
        vector<int> o;
        help(a,target,ans,0,o);
        return ans;
    
    }
    
};