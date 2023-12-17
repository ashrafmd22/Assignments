/*Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(auto i:strs){
            string x(i);
            sort(x.begin(),x.end());
            m[x].push_back(i);
        }
        vector<vector<string>> vect;
        for(auto i:m)
            vect.push_back(i.second);
        return vect;
    }
};