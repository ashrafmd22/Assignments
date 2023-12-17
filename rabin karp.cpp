#include <iostream>
#include <cmath>
using namespace std;

#define d 256

void search(string pattern, string text, int q) {
    int m = pattern.size();
    int n = text.size();
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = pow(d, m - 1) % q; // modulo value

    // Calculate the hash value of pattern and the first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over the text one by one
    for (int i = 0; i <= n - m; i++) {
        // Check the hash values of the current window of text and pattern
        if (p == t) {
            // If hash values match, check character by character
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate the hash value for the next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    int q = 101; // A prime number
    search(pattern, text, q);

    return 0;
}
