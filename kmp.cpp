#include <iostream>
#include <vector>
using namespace std;

// Function to compute the LPS (Longest Prefix Suffix) array
vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0; // length of previous longest prefix suffix

    for (int i = 1; i < m;) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1]; // fallback
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP Pattern Search Algorithm
void KMP(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0; // i for text, j for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // prepare for next match
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1]; // fallback
            else
                i++;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    cout << "Text: " << text << "\n";
    cout << "Pattern: " << pattern << "\n\n";
    KMP(text, pattern);

    return 0;
}
