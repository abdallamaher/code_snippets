#include <bits/stdc++.h>
using namespace std;
#define ll long long


inline void solve() {
    string s; cin >> s;
    int  n = s.size();
    vector<int> pos[4];
    for (int i = 0; i < n;i++) {
        pos[s[i] - '0'].push_back(i);
    }
    int ans = 1e9;
    for (int i = 0;i < n; i++) {
        auto a = lower_bound(pos[1].begin(), pos[1].end(), i);
        auto b = lower_bound(pos[2].begin(), pos[2].end(), i);
        auto c = lower_bound(pos[3].begin(), pos[3].end(), i);
        if (a == pos[1].end() || b == pos[2].end() || c == pos[3].end())continue;
        int mn = min({ *a, *b, *c });
        int mx = max({ *a, *b, *c });
        ans = min(ans, mx - mn + 1);
    }
    if (ans == 1e9)cout << 0 << endl;
    else cout << ans << endl;
}

void go() {
    string s; cin >> s;
    vector<pair<char, int>> v;
    for (auto c : s) {
        if (v.empty() || v.back().first != c) {
            v.push_back({ c, 1 });
        }
        else {
            v.back().second++;
        }
    }
    int ans = 1e9;
    int n = v.size();
    for (int i = 1; i < n - 1; i++) {
        if (v[i - 1].first != v[i + 1].first) {
            ans = min(ans, v[i].second + 2);
        }
    }
    if (ans == 1e9)cout << 0 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)go();
}