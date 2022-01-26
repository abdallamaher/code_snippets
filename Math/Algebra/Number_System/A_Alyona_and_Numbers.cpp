#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int a, b; cin >> a >> b;
    if (b > a)swap(a, b);   // b is min
    ll ans = 0;
    for (int i = 1; i <= b; i++) {
        ans += (i + a) / 5 - i / 5;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}