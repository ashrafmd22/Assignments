/* Partition Labels

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int freq[26] = {};
        map<char,int> mp;
        vector<int> ans;
        int sz = 0;
        for(char&e: s) freq[e-'a']++;
        for(char&e: s){
            if(!mp.count(e)){
                if(freq[e-'a']-1) mp.insert({e,freq[e-'a']-1});
                sz += freq[e-'a'];
            }    
            else if(--mp[e] == 0) mp.erase(e);
            if(size(mp) == 0){
                ans.push_back(sz);
                sz = 0;
            }
        }
        return ans;
    }
};