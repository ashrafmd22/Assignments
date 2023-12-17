/*Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=1;
        // int cnt=1;
        
        unordered_set<char> st;
        int i=0;
        int j=0;
        st.insert(s[0]);
        while(j<s.size()-1){
            if(st.count(s[j+1])>0){
                st.erase(s[i]);
                i++;
            }
            else{
                // cnt++;
                j++;
                ans=max(ans,j-i+1);
                
                st.insert(s[j]);
            }
        }
        return ans;
    }
};