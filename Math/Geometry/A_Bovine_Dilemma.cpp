#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> v(n + n);
    for (int i = 0;i < n; i++) {
        scanf("%d", &v[i]);
    }
    ll ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1;j < n; j++) {
            int x = v[j] - v[i];
            if (mp[x] == 0)ans++;
            mp[x] = 1;
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}