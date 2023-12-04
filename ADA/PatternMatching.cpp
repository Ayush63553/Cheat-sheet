#include <bits/stdc++.h>
using namespace std;

#define d 256

void rabinKarp(string text, string pattern, int prime) {
    int N = text.size();
    int M = pattern.size();
    int t = 0, p = 0, h = 1;
    for (int i = 0; i < M - 1; i++)
        h = (h * d) % prime;
    for (int i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % prime;
        t = (d * t + text[i]) % prime;
    }
    for (int i = 0; i <= N - M; i++) {
        if (p == t) {
            int j = 0;
            for (; j < M; j++)
                if (text[i + j] != pattern[j]) break;
            if (j == M) cout << "Pattern found at index " << i << endl;
        }
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % prime;
            if (t < 0) t += prime;
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);
    rabinKarp(text, pattern, 13);
    return 0;
}