#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
map<ll, vector<ll>> adj;
map<ll, int> vis;
set<ll> st;
void dfs(ll x, vector<ll> v = {}) {
    if (v.size() == n) {

        for (auto& it : v) {
            cout << it << ' ';
        }
        exit(0);
    }
    if (vis[x])return;
    vis[x]++;
    if (st.count(x * 2)) {
        v.push_back(x * 2);
        dfs(x * 2, v);
        v.pop_back();
    }
    if (x % 3 == 0 && st.count(x / 3)) {
        v.push_back(x / 3);
        dfs(x / 3, v);
    }
}
inline void solve() {
    cin >> n;
    ll ar[200] = {};
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        st.insert(ar[i]);
    }
    for (int i = 0;i < n; i++) {
        vis.clear();
        dfs(ar[i], { ar[i] });
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}