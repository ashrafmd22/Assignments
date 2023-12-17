#include <iostream>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && wordDict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    string s = "leetcode";
    unordered_set<string> wordDict = {"leet", "code"};
    if (wordBreak(s, wordDict))
        cout << "The string can be segmented." << endl;
    else
        cout << "The string cannot be segmented." << endl;

    return 0;
}
