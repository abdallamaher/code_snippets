#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

inline void solve() {
    debug();
    int n; cin >> n;
    string s; cin >> s;
    vector<int> v(n), taken(n);
    priority_queue<int> p;
    int cnt = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (s[i] == '1') {
            cnt++;
            p.push(v[i]);
            taken[i] = 1;
            if (i && taken[i - 1] == 0)p.push(v[i - 1]);
        }
        if (s[i] == '0' || i == n - 1) {
            debug(cnt, p.size());
            while (cnt-- && p.size()) {
                debug(p.top());
                sum += p.top();
                p.pop();
            }
            while (p.size())p.pop();
            cnt = 0;
        }
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}