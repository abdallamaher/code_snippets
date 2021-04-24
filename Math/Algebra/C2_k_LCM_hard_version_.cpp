#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; scanf("%d %d", &n, &k);
    while (k > 3) {
        printf("1 ");
        k--;
        n--;
    }

    if (n & 1) {
        printf("1 %d %d\n", n / 2, n / 2);
        return;
    }

    if (n % 4 == 0) {
        printf("%d %d %d\n", n / 4, n / 4, n / 2);
    }
    else {
        printf("2 %d %d\n", (n - 1) / 2, (n - 1) / 2);
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}