/*Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));  // dp table to store the results
        int maxlen = 0;  // length of the longest palindromic substring
        int start = -1;  // starting index of the longest palindromic substring
        
        // Loop over different lengths of substrings
        for (int diff = 0; diff < s.size(); diff++) {
            // Loop over all possible starting indices of substrings
            for (int i = 0, j = diff; j < n; i++, j++) {
                // Base case: length 1 substring is a palindrome
                if (diff == 0) {
                    dp[i][j] = 1;
                    if (diff + 1 > maxlen) {
                        start = i;
                        maxlen = diff + 1;
                    }
                }
                // Base case: length 2 substring is a palindrome if the characters are equal
                else if (diff == 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                        if (diff + 1 > maxlen) {
                            start = i;
                            maxlen = diff + 1;
                        }
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
                // For substrings of length greater than 2
                else {
                    // Check if the characters at the endpoints are equal and the inner substring is a palindrome
                    if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                        dp[i][j] = 1;
                        if (diff + 1 > maxlen) {
                            start = i;
                            maxlen = diff + 1;
                        }
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        
        string ans = "";
        // Construct the longest palindromic substring using the starting index and length
        for (int i = start; i < start + maxlen; i++) {
            ans += s[i];
        }
        
        return ans;
    }
};