#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    /*
    optimal is to first keep increase 1 to x
    then n = y * x
    which is 
         n = x * y
    so as it's divisor we can iterate till (i * i <= n)
    */
    int ans = 1e9;
    for (int i = 1;i * i <= n;i++) {
        ans = min(ans, i - 1 + (int)ceil(1.0 * (n - i) / i));
        // ans = min(ans, i - 1 + (n - 1) / i);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}