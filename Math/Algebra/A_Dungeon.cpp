#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int a, b, c;cin >> a >> b >> c;
    ll s = a + b + c;
    puts(s % 9 == 0 && min({ a,b, c }) >= s / 9 ? "YES" : "NO");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}