#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, k; cin >> n >> k;
    int p = 1; ll ans = 0;
    for (int i = 0;i < k; i++) {
        int x; scanf("%d", &x);
        if (x < p)
            ans += n - abs(x - p);
        else
            ans += x - p;
        p = x;
    }
    printf("%lld", ans);
    return 0;
}