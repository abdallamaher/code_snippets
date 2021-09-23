#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> v(n + n), vis(n + n);
    for (int i = 1; i <= n;i++) cin >> v[i];
    for (int i = 1; i <= n;i++) {
        if (vis[i])continue;
        int cur = i;
        vector<int> ar;
        ar.push_back(i);
        while (i != v[cur]) {
            ar.push_back(v[cur]);
            cur = v[cur];
        }
        for (auto& it : ar)vis[it] = ar.size();
    }
    for (int i = 1; i <= n; i++)cout << vis[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}