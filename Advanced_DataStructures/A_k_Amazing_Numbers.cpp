#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

inline void solve() {
    int n; scanf("%d", &n);
    vector<int> v(n + n), dis(n + n, 1e9);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        mp[v[i]].push_back(i);
    }
    for (auto& it : mp) {
        int mx_Gap = it.second[0];
        it.second.push_back(n + 1);
        for (int i = 1; i < it.second.size(); i++) {
            mx_Gap = max(mx_Gap, it.second[i] - it.second[i - 1]);
        }
        dis[mx_Gap] = min(dis[mx_Gap], it.first);
    }
    for (int i = 1; i <= n; i++) {
        dis[i] = min(dis[i], dis[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d%c", dis[i] == 1e9 ? -1 : dis[i], " \n"[i == n]);
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}