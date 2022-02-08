#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll a, b; cin >> a >> b;
    if (b == 1) {
        cout << "NO\n" << endl;
        return;
    }
    // a*b    nearly to a*b        nearly as it's coprime to a*b
    cout << "YES\n" << a * b << ' ' << a << ' ' << a * (b + 1) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}