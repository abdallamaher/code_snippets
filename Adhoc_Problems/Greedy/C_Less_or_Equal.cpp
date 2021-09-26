#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; cin >> n >> k;
    int ar[n + 1] = {};
    ar[0] = 1;
    for (int i = 1; i <= n; i++)cin >> ar[i];
    sort(ar + 1, ar + n + 1);
    if (k == n || ar[k] != ar[k + 1]) {
        cout << ar[k];
    }
    else {
        cout << -1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}