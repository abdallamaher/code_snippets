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
    char c; cin >> c;
    string s; cin >> s;

    vector<int> mp(n, -1);
    stack<int> st;

    // map
    for (int i = 0; i < n; i++) {
        while (st.size() && s[i] == 'g') {
            int t = st.top(); st.pop();
            mp[t] = i;
        }

        if (s[i] != 'g')st.push(i);
        else mp[i] = 0;
    }
    // debug(s);
    // debug(mp);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == c) {
            int ans1 = 0;
            if (mp[i] == -1) {
                ans1 = n - i + mp[0];
            }
            else {
                ans1 = mp[i] - i;
            }
            ans = max(ans, ans1);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}