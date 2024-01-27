#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    string s; cin >> s;
    int n = (int)s.size();

    int x[n + n] = {}, y[n + n] = {};

    for (int i = 0;i < n; i++) {
        y[i + 1] = y[i], x[i + 1] = x[i];
        if (s[i] == 'U')y[i + 1]++;
        if (s[i] == 'D')y[i + 1]--;
        if (s[i] == 'R')x[i + 1]++;
        if (s[i] == 'L')x[i + 1]--;
    }

    int ans = 0;
    for (int pos = 1; pos <= n; pos++) {
        int xx = 0, yy = 0;
        for (auto c : s) {
            int tmp1 = xx, tmp2 = yy;
            if (c == 'U')yy++;
            if (c == 'D')yy--;
            if (c == 'R')xx++;
            if (c == 'L')xx--;

            if (yy == y[pos] && xx == x[pos]) {
                xx = tmp1, yy = tmp2;
            }

        }
        if (yy == 0 && xx == 0) {
            ans = pos;
            break;
        }
    }
    printf("%d %d\n", x[ans], y[ans]);
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}