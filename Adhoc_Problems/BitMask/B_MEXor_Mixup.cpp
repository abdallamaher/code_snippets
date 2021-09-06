#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Method to calculate xor
int computeXOR(int n) {
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}

inline void solve() {
    int a, b; cin >> a >> b;
    int ans = a;
    int xr = computeXOR(a - 1); // or pre_Calculate from[0-1e6]
    if (xr == b)ans = ans;
    else if ((xr ^ b) != a)ans++;
    else ans += 2;
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}