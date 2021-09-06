#include <bits/stdc++.h>
using namespace std;
#define ll long long


inline void solve() {
    int n; cin >> n;
    int a = 0, b = 0;
    int mul = 1;
    while (n != 0) {
        a += (n % 10) * mul;
        n /= 10;
        b += (n % 10) * mul;
        n /= 10;
        mul *= 10;
    }
    cout << (a + 1) * (b + 1) - 2 << endl;
}
int main() {
    int t; cin >> t;
    while (t--)solve();
}