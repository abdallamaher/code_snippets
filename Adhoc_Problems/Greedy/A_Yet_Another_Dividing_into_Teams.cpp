#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& it : v)cin >> it;
    sort(v.begin(), v.end());
    int ans = 1;
    for (int i = 1;i < n; i++) {
        if (v[i] - v[i - 1] == 1)ans = 2;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}