#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int x, y, z; cin >> x >> y >> z;
    int a = sqrt(x * z / y);
    int b = sqrt(x * y / z);
    int c = sqrt(z * y / x);
    cout << 4 * (a + b + c) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}