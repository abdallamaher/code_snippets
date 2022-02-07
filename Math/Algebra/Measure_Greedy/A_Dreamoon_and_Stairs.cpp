#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll n, k; cin >> n >> k;
    ll x = (n + 1) / 2;
    x = (x + k - 1) / k * k;
    cout << (x <= n ? x : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}