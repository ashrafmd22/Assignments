/*Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 */
 class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));  // dp table to store the results
        int maxlen = 0;  // length of the longest palindromic substring
        int start = -1;  // starting index of the longest palindromic substring
        
        // Loop over different lengths of substrings
        int cnt=0;
        for (int diff = 0; diff < s.size(); diff++) {
            // Loop over all possible starting indices of substrings
            for (int i = 0, j = diff; j < n; i++, j++) {
                // Base case: length 1 substring is a palindrome
                if (diff == 0) {
                    dp[i][j] = 1;
                    
                }
                // Base case: length 2 substring is a palindrome if the characters are equal
                else if (diff == 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                        
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
                        
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
                if(dp[i][j]==1) cnt++;
            }
        }
        
        
        return cnt;
    }
};