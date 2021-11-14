#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    // -1 - ( +2)   -3
    // +1 - ( -2)   +3

    if (((a + c) - 2 * b) % 3 == 0)cout << 0 << endl;
    else cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}