/* Count Unique Characters of All Substrings of a Given String

Let's define a function countUniqueChars(s) that returns the number of unique characters in s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.*/
class Solution {
public:
    int uniqueLetterString(string s) {
        map<char,vector<int>> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]].push_back(i);
        }
        int ans=0;
        for(auto it:mp)
        {
            int n=it.second.size();
            for(int i=0;i<it.second.size();i++)
            {
                int l=(i==0)?it.second[i]+1:it.second[i]-it.second[i-1];
                int r=(i==n-1)?s.size()-it.second[i]:it.second[i+1]-it.second[i];
                ans+=(l*r);
            }
        }
        return ans;
    }
};