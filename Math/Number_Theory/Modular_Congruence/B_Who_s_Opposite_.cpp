#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int a, b, c; cin >> a >> b >> c;
    int num = abs(a - b);
    if (max({ a, b, c }) > num * 2) {
        puts("-1");
        return;
    }
    if (c + num > 2 * num) printf("%d\n", c - num);
    else printf("%d\n", c + num);
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}