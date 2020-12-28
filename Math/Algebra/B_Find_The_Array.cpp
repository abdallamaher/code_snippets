#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    int ar[n] = {};
    // total_sum = even_sum + odd_sum;
    ll sum = 0, odd_sum = 0;
    for (int i = 0; i < n;i++) {
        scanf("%d", &ar[i]);
        if (i % 2)odd_sum += ar[i];
        sum += ar[i];
    }
    for (int i = bool(2 * odd_sum <= sum); i < n; i += 2)ar[i] = 1;

    for (int i = 0; i < n;i++)printf("%d%c", ar[i], " \n"[i == n - 1]);
}

inline void solve1() {
    int n; cin >> n;
    for (int i = 0;i < n; i++) {
        int x; scanf("%d", &x); //roundDown to closes power of 2    so 30 become 16   and   2 * (30 - 16) <= 30
        int lg = log2(x);
        printf("%d%c", 1 << lg, " \n"[i == n - 1]);
    }
}

inline void solve2() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        x = 32 - __builtin_clz(x) - 1;
        printf("%d%c", 1 << x, " \n"[i == n - 1]);
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}