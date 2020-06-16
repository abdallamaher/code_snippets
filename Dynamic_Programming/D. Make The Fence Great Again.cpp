#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5 + 5;
int q, n, x;
int h[N], p[N];
ll dp[N][4];

ll solve(int i, int pr) {
    if (i > n)return 0;
    ll& ret = dp[i][pr];
    if (~ret)return ret;

    ret = 1e17;
    for (int j = 0; j < 3; j++) {
        if(h[i] + j != h[i-1] + pr)
            ret = min(ret, solve(i + 1, j) + 1ll * p[i] * j);
    }
    return ret;
}

int main() {
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++)
            for(int j=0; j<3; j++)
                dp[i][j] = -1;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", h + i, p + i);
        }
        printf("%lld\n", solve(1, 0));
    }
    return 0;
}

