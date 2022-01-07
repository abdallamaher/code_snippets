#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    map<int, int> mp;
    int alone = 0, mx = 1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (mp[x] == 0) {
            alone++;
            mp[x]++;
        }
        else {
            mp[x]++;
            mx = max(mx, mp[x]);
        }
    }
    int a = min(mx, alone - 1);
    int b = min(mx - 1, alone);
    cout << max(a, b) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}