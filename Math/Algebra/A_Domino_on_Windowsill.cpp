#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k1, k2, w, b;
    scanf("%d %d %d %d %d", &n, &k1, &k2, &w, &b);
    int mx = (max(k1, k2) - min(k1, k2)) / 2;
    int white = min(k1, k2) + mx;
    int black = n - max(k1, k2) + mx;
    puts(white >= w && black >= b ? "yes" : "no");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}