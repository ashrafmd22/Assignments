#include <iostream>
using namespace std;

bool isMatch(string str, string pattern) {
    int m = str.size();
    int n = pattern.size();

    // Create a table to store results of sub-problems
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Empty pattern matches empty string
    dp[0][0] = true;

    // Only '*' can match with an empty string
    for (int j = 1; j <= n; j++) {
        if (pattern[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    // Build the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (pattern[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
        }
    }

    return dp[m][n];
}

int main() {
    string str = "baaabab";
    string pattern = "*****ba*****ab";
    if (isMatch(str, pattern))
        cout << "Pattern matches the string." << endl;
    else
        cout << "Pattern does not match the string." << endl;

    return 0;
}
