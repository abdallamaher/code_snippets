#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int m = count(s.begin(), s.end(), 'M');
    int t = count(s.begin(), s.end(), 'T');
    int ok = (t == 2 * m);
    for (int cnt = 0, i = 0; i < n; i++) {
        if (s[i] == 'M')cnt--;
        else cnt++;

        if (cnt < 0)ok = 0;
    }

    for (int cnt = 0, i = n - 1; i >= 0; i--) {
        if (s[i] == 'M')cnt--;
        else cnt++;

        if (cnt < 0)ok = 0;
    }

    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}