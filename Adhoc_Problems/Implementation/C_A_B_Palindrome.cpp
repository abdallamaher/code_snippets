#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
2 3
???1?
*/
inline void solve() {
    int a, b; string s;
    cin >> a >> b >> s;
    int n = s.size();

    for (int i = 0;i < (n + 1) / 2; i++) {
        if (s[i] == '?' || s[n - i - 1] == '?') {
            if (s[i] == '?')s[i] = s[n - i - 1];
            else if (s[n - i - 1] == '?')s[n - i - 1] = s[i];
        }
    }

    int cnt[3] = {};
    for (auto& c : s)cnt[c - '0']++;

    for (int i = 0;i < (n + 1) / 2; i++) {
        int cur = 1 + (i != n - i - 1);
        if (s[i] == '?' && s[n - i - 1] == '?') {
            if (cnt[0] + cur <= a) {
                s[i] = s[n - i - 1] = '0';
                cnt[0] += cur;
            }
            else if (cnt[1] + cur <= b) {
                s[i] = s[n - i - 1] = '1';
                cnt[1] += cur;
            }
        }
    }

    int ok = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        if (s[i] != s[n - i - 1])ok = 1;
    }

    if (ok || cnt[0] != a || cnt[1] != b) {
        cout << "-1\n";
    }
    else {
        cout << s << endl;
    }
}
int main() {
    int t; cin >> t;
    while (t--)solve();
}