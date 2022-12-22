#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string st;
    if (s[0] == '9') st = string(n + 1, '1');
    else st = string(n, '9');

    reverse(s.begin(), s.end());
    reverse(st.begin(), st.end());

    string ans;
    int preCost = 0;
    for (int i = 0; i < n; i++) {
        int t = st[i] - preCost - s[i];
        if (t < 0) {
            t = t + 10;
            preCost = 1;
        }
        else {
            preCost = 0;
        }
        ans += (t + '0');
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}