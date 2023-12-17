#include <iostream>
using namespace std;

string smallestNonPalindromicSubstring(string s) {
    int n = s.size();
    string rev = s;
    reverse(rev.begin(), rev.end());

    if (s != rev)
        return s;

    int i = 0;
    while (i < n / 2 && s[i] == 'a')
        i++;

    if (i == n / 2)
        s[n - 1] = 'b';
    else
        s[i] = 'a';

    return s;
}

int main() {
    string s = "aaaa";
    cout << "Lexicographically Smallest Non-Palindromic Substring: " << smallestNonPalindromicSubstring(s) << endl;

    return 0;
}
