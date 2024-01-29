#include <iostream>
#include <string>
#include <vector>

using namespace std;

void computeLastTable(const string& pattern, vector<int>& Last) {
    for (int i = 0; i < pattern.length(); i++) {
        Last[pattern[i]] = i;
    }
}

void computeBMNext(const string& pattern, vector<int>& BMNext, vector<int>& Pi) {
    int i, b;

    for (i = 0; i <= pattern.length(); i++) BMNext[i] = 0;
    i = pattern.length();
    b = pattern.length() + 1;
    Pi[i] = b;
    while (i > 0) {
        while ((b <= pattern.length()) && (pattern[i - 1] != pattern[b - 1])) {
            if (BMNext[b] == 0) BMNext[b] = b - i;
            b = Pi[b];
        }
        Pi[--i] = --b;
    }

    b = Pi[0];
    for (i = 0; i <= pattern.length(); i++) {
        if (BMNext[i] == 0) BMNext[i] = b;
        if (i == b) b = Pi[b];
    }
}

void searchPattern(const string& text, const string& pattern) {
    int N = text.length();
    int M = pattern.length();

    vector<int> Last(256, -1);  // Zakładamy, że używamy ASCII
    computeLastTable(pattern, Last);

    vector<int> BMNext(M + 1, 0);
    vector<int> Pi(M + 1, 0);
    computeBMNext(pattern, BMNext, Pi);

    cout << pattern << endl;
    cout << text << endl;

    int pp = 0;
    int i = 0;

    while (i <= N - M) {
        int j = M - 1;
        while ((j > -1) && (pattern[j] == text[i + j])) j--;
        if (j == -1) {
            while (pp < i) {
                cout << " ";
                pp++;
            }
            cout << "^";
            pp++;
            i += BMNext[0];
        } else {
            i += max(BMNext[j + 1], j - Last[text[i + j]]);
        }
    }

    cout << endl;
}

int main() {
    string s = "A big black bug bit a big black bear";
    string p = "big black";

    searchPattern(s, p);

    return 0;
}
