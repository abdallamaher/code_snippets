#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1)a++;
        else b++;
    }
    int ok = 1;
    if (a % 2)ok = 0;
    else if (b % 2 && a == 0)ok = 0;
    puts(ok ? "YES" : "NO");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}