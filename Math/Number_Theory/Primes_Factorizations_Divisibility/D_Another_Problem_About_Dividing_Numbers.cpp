#include <bits/stdc++.h>
using namespace std;
#define ll long long

int cntPrimeFac(int x) {
    int res = 0;
    for (int i = 2; i * i <= x;i++) {
        if (x % i)continue;
        while (x % i == 0)res++, x /= i;
    }
    if (x != 1)res++;
    return res;
}

inline void solve() {
    int a, b, k; cin >> a >> b >> k;
    if (k == 1) {
        if (b > a)swap(a, b);
        puts(a % b == 0 && a != b ? "YES" : "NO");
        return;
    }
    int mxMoves = cntPrimeFac(a) + cntPrimeFac(b);
    puts(mxMoves >= k ? "YES" : "NO");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}