/*First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.*/

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> hmap;
        for (int idx{}; idx < s.size(); idx++) {
            // Everytime the character appears in the string, add one to its count
            hmap[s[idx]]++;
        }
        // Traverse the string from the beginning...
        for (int idx{}; idx < s.size(); idx++) {
            // If the count of the char is equal to 1, it is the first distinct character in the list.
            if (hmap[s[idx]] == 1)
                return idx;
        } 
        return -1;     // if no character appeared exactly once...
    }
};