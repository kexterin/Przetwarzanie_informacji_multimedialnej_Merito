// Morrisa-Pratta
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void computePIArray(const string& pattern, vector<int>& PI) {
    int M = pattern.length();
    int b = -1;

    PI[0] = b;

    for (int i = 1; i <= M; i++) {
        while ((b > -1) && (pattern[b] != pattern[i - 1])) {
            b = PI[b];
        }
        PI[i] = ++b;
    }
}

void searchPattern() {
    string s = "ababcababcabcabc";
    string p = "abcabc";

    int N = s.length();
    int M = p.length();

    vector<int> PI(M + 1, 0);
    computePIArray(p, PI);

    cout << p << endl;

    cout << s << endl;

    int pp = 0;
    int b = 0;

    for (int i = 0; i < N; i++) {
        while ((b > -1) && (p[b] != s[i])) {
            b = PI[b];
        }
        if (++b == M) {
            while (pp < i - b + 1) {
                cout << " ";
                pp++;
            }
            cout << "^";
            pp++;
            b = PI[b];
        }
    }

    cout << endl;
}

int main() {
    searchPattern();
    return 0;
}
