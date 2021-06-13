#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> v;
    v.push_back(0);
    for (int i = 0;i < n; i++) {
        int x; scanf("%d", &x);
        v.push_back(x);
    }
    v.push_back(0);
    ll ans = 0;
    for (int i = 1;i <= n; i++) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            int t = max(v[i - 1], v[i + 1]);
            ans += v[i] - t;
            v[i] = t;
        }
    }
    for (int i = 1;i <= n; i++) {
        ans += abs(v[i] - v[i - 1]);
        if (i == n)ans += v[i];
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}