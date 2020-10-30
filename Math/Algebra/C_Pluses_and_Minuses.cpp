#include <bits/stdc++.h>
using namespace std;
#define ll long long 

inline void solve() {
    string s; cin >> s;
    ll res = 0;
    int cur = 0;
    for (int i = 0; s[i]; i++) {
        (s[i] == '+') ? cur-- : cur++;
        if (cur > 0)res += i + 1, cur = 0;
    }
    cout << res + s.size() << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}