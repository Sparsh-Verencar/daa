#include <iostream>
#include <vector>
using namespace std;

/* int charToVal(char c) {
    if (c == 'A') return 1;
    if (c == 'B') return 2;
    return 3;
}

int computeHash(string s) {
    int hash = 0;
    for (char c : s) {
        hash = hash * 10 + charToVal(c);
    }
    return hash % 17;
}

void rk(string text, string pattern) {
    vector<int> solutionIndex;
    int patternLen = pattern.length();
    int textLen = text.length();

    if (patternLen > textLen) return;

    int patternHash = computeHash(pattern);

    for (int i = 0; i <= textLen - patternLen; i++) {
        string sub = text.substr(i, patternLen);
        int subHash = computeHash(sub);

        if (subHash == patternHash) {
            if (sub == pattern) {
                solutionIndex.push_back(i);
            } else {
                cout << "Spurious hit at index " << i << endl;
            }
        }
    }

    cout << "\nPattern found at indexes:\n";
    for (int idx : solutionIndex) {
        cout << idx << "\t";
    }
    cout << endl;
} */

int charToVal(char c)
{
    if (c == 'A')
        return 1;
    if (c == 'B')
        return 2;
    return 3;
}

int hashf(string str)
{
    int hash = 0;
    for (auto c : str)
    {
        hash = hash * 10 + charToVal(c);
    }
    return hash;
}

void rk(string text, string pattern)
{
    int patternLength = pattern.length();
    int textLength = text.length();
    vector<int> solution;
    int patternHash = hashf(pattern);

    for (int i = 0; i <= textLength - patternLength; i++)
    {
        string sub = text.substr(i, patternLength);
        int subHash = hashf(sub);

        if (subHash == patternHash)
        {
            if (sub == pattern)
            {
                solution.push_back(i);
                cout << "Solution added" << endl;
            }
            else
            {
                cout << "Spurious hit at index " << i << endl;
            }
        }
    }
    cout << "\nPattern found at indexes:\n";
    for (int idx : solution)
    {
        cout << idx << "\t";
    }
    cout << endl;
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    cout << "Text: " << text << "\n";
    cout << "Pattern: " << pattern << "\n\n";

    rk(text, pattern);

    return 0;
}
