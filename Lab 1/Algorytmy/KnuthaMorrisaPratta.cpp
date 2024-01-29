// Knutha-Morrisa-Pratta
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void computeKMPNext(const string& pattern, vector<int>& KMPNext) {
    int M = pattern.length();
    int b = -1;

    KMPNext[0] = b;

    for (int i = 1; i <= M; i++) {
        while ((b > -1) && (pattern[b] != pattern[i - 1])) {
            b = KMPNext[b];
        }
        ++b;
        if ((i == M) || (pattern[i] != pattern[b])) {
            KMPNext[i] = b;
        } else {
            KMPNext[i] = KMPNext[b];
        }
    }
}

void searchPattern(const string& text, const string& pattern) {
    int N = text.length();
    int M = pattern.length();

    vector<int> KMPNext(M + 1, 0);
    computeKMPNext(pattern, KMPNext);

    cout << pattern << endl;
    cout << text << endl;

    int pp = 0;
    int b = 0;

    for (int i = 0; i < N; i++) {
        while ((b > -1) && (pattern[b] != text[i])) {
            b = KMPNext[b];
        }
        if (++b == M) {
            while (pp < i - b + 1) {
                cout << " ";
                pp++;
            }
            cout << "^";
            pp++;
            b = KMPNext[b];
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
