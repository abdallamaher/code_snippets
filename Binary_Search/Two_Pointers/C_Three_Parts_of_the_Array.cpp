#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    ll s1 = 0, s2 = 0, ans = 0;
    int a = 0, b = n - 1;
    while (a <= b) {
        if (s1 < s2) {
            s1 += v[a];
            a++;
        }
        else {
            s2 += v[b];
            b--;
        }
        if (s1 == s2)ans = max(ans, s1);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}