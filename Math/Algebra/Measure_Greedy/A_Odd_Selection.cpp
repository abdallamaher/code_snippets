#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; cin >> n >> k;
    int odd = 0, even = 0;
    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        if (x & 1)odd++;
        else even++;
    }

    if (odd) {
        k--, odd--;
        k -= min(k - bool(k & 1), (odd / 2) * 2);
        k -= min(k, even);
    }
    cout << (k <= 0 ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}