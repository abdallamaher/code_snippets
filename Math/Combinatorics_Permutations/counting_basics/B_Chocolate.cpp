#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (count(v.begin(), v.end(), 1) == 0) {
        cout << 0 << endl;
        return;
    }
    ll res = 1;
    for (int i = 0; i < n; i++) {
        if (v[i]) {
            int cnt = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (v[j]) {
                    res *= (cnt + 1);
                    break;
                }
                cnt++;
            }
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}