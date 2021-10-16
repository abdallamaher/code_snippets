#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (mp[x].empty())mp[x].push_back(-1);
        mp[x].push_back(i);
    }
    int ans = 1e9;
    for (auto& [key, v] : mp) {
        int tmp = 0;
        v.push_back(n);
        for (int i = 1; i < v.size(); i++) {
            if (v[i] - v[i - 1] > 1)tmp++;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}

void go() {
    int n; cin >> n;
    // vector<int> in(n);
    vector<int> in;
    vector<int> res(n + 1, 1);  // 2 + gaps
    for (int i = 0; i < n; i++) {
        // cin >> in[i];
        int x; cin >> x;
        if (in.empty() || in.back() != x)in.push_back(x);
    }
    // n = unique(in.begin(), in.end()) - in.begin();
    // in.resize(n);
    n = in.size();
    for (int i = 0; i < n; i++)res[in[i]]++;
    res[in[0]]--;
    res[in[n - 1]]--;

    int ans = 1e9;
    for (int i = 0;i < n; i++)ans = min(ans, res[in[i]]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)go();
}