/*Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.*/

class Solution {
public:
    void help(vector<int>& a,int i,vector<vector<int>>& ans){
        if(i==a.size()){
            ans.push_back(a);
            return ;
        }

        for(int j=i;j<a.size();j++){
                swap(a[i],a[j]);
                help(a,i+1,ans);
                swap(a[i],a[j]);
        }

    }
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>> ans;
        
        help(a,0,ans);
        return ans;
    }
};