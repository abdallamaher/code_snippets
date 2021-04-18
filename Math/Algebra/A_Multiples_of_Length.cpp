#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; scanf("%d", &n);
    int ar[n + n] = {};
    for (int i = 1;i <= n; i++) {
        scanf("%d", ar + i);
    }

    if (n == 1) {
        printf("1 1\n%d\n", -ar[1]);
        printf("1 1\n%d\n", 0);
        printf("1 1\n%d\n", 0);
        return 0;
    }

    // ar[i](-n + 1)
    printf("1 %d\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", -1ll * n * ar[i]);
    }


    printf("\n1 %d\n", n - 1);
    for (int i = 1; i < n; i++) {
        printf("%lld ", 1ll * (n - 1) * ar[i]);
    }


    printf("\n%d %d\n%lld", n, n, 1ll * (n - 1) * ar[n]);
}