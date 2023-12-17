#include <iostream>
#include <unordered_set>
using namespace std;

int countDistinctSubstrings(string s) {
    unordered_set<string> substrings;

    for (int i = 0; i < s.size(); i++) {
        string substring = "";
        for (int j = i; j < s.size(); j++) {
            substring += s[j];
            substrings.insert(substring);
        }
    }

    return substrings.size();
}

int main() {
    string s = "abc";
    cout << "Count of distinct substrings: " << countDistinctSubstrings(s) << endl;

    return 0;
}
