#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

const int N = 100;
int ar[N];

inline void solve() {
    int n; cin >> n;
    map<int, vector<int>> v;
    for (int i = 0; i < n; i++) {
        int  x; cin >> x;
        v[x].push_back(i);
    }
    string s; cin >> s;
    debug(s);
    int flag = true;
    for (auto& x : v) {
        auto it = x.second;
        for (int i = 0; i < it.size(); i++) if (s[it[i]] != s[it[0]])flag = false;
        debug(it, flag);
    }
    cout << (flag ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}