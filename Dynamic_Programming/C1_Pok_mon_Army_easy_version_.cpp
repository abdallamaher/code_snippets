#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int n, q;
const int N = 3e5 + 5;
int ar[N];
ll dp[N][2];

ll solve(int i=0, int f=0){
    if(i == n)return 0;
    ll &ret = dp[i][f];
    if(~ret)return ret;
    ret = solve(i + 1, f);
    if(f) ret = max(ret, solve(i + 1, 0) - ar[i]);
    else ret = max(ret, solve(i + 1, 1) + ar[i]);
    return ret;
}

int main() {
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &q);
        for(int i=0;i <n; i++)scanf("%d", ar + i);
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", solve());
    }
	return 0;
}