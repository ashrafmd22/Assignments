/* Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.*/

class Solution {
public: void help(string mapping[],vector<string>& ans,string digits,int i,string& o){
    if(i==digits.length()){
        ans.push_back(o);
        return;
    }
    int n=digits[i]-'0';
    string val=mapping[n];
    for(int j=0;j<val.size();j++){
        o.push_back(val[j]);
        help(mapping,ans,digits,i+1,o);
        o.pop_back();
    }
} 
    vector<string> letterCombinations(string digits) {
        string mapping []={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.size()==0) return ans;
        string o;
        help(mapping,ans,digits,0,o);
        return ans;
    }
};