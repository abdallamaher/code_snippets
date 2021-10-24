#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll a, b, c; cin >> a >> b >> c;
    int cnt = 0;
    cnt += (a % 2);
    cnt += (b * 2 % 2);
    cnt += (c * 3 % 2);
    cout << (cnt % 2) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}