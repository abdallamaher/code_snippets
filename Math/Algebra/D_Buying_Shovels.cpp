#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);
        int d = 1;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i <= k && i > d)d = i;
                int x = n / i;
                if (x <= k && x > d)d = x;
            }
        }
        printf("%d\n", n / d);
    }
    return 0;
}