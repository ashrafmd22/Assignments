/*Word Break II

Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.*/
class Solution {
public:
    unordered_map<string, vector<string>> mp;
    vector<string> wordBreak(string s, vector<string>& a) {
        if(mp.count(s)>0) return mp[s];
        vector<string> ans;
        if(find(a.begin(),a.end(),s)!=a.end()) ans.push_back(s);
        for(int i=1;i<s.size();i++){
            string left=s.substr(0,i);
            if(find(a.begin(),a.end(),left)!=a.end()){
                vector<string> smallans=wordBreak(s.substr(i),a);
                for(string sen:smallans){
                    ans.push_back(left+" "+sen);
                }
            }
        }
        mp[s]=ans;
        return ans;
    }
};