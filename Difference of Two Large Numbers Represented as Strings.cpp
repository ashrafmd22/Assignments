#include <iostream>
using namespace std;

bool isSmaller(string str1, string str2) {
    int n1 = str1.size(), n2 = str2.size();
    if (n1 < n2) return true;
    if (n1 > n2) return false;

    for (int i = 0; i < n1; i++) {
        if (str1[i] < str2[i]) return true;
        if (str1[i] > str2[i]) return false;
    }

    return false;
}

string findDifference(string str1, string str2) {
    if (isSmaller(str1, str2)) swap(str1, str2);

    string result = "";
    int n1 = str1.size(), n2 = str2.size();
    int carry = 0;

    for (int i = n1 - 1; i >= n2 - 1; i--) {
        int sub = (str1[i] - '0') - (str2[i - (n1 - n2)] - '0') - carry;
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result = to_string(sub) + result;
    }

    for (int i = n1 - n2 - 1; i >= 0; i--) {
        if (str1[i] == '0' && carry) {
            result = "9" + result;
            continue;
        }

        int sub = (str1[i] - '0') - carry;
        if (i > 0 || sub > 0) {
            result = to_string(sub) + result;
        }

        carry = 0;
    }

    return result;
}

int main() {
    string str1 = "1000";
    string str2 = "99";
    cout << "Difference: " << findDifference(str1, str2) << endl;

    return 0;
}
