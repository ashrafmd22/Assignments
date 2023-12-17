#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
        return "";

    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs.back();
    int len = min(first.size(), last.size());
    int i = 0;
    while (i < len && first[i] == last[i]) {
        i++;
    }

    return first.substr(0, i);
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;

    return 0;
}
