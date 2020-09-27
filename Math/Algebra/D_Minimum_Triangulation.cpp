#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll dp[550][550];
ll solve(int i, int j){
    if(abs(i-j) < 2)return 0;
    ll&ret = dp[i][j];
    if(~ret)return ret;
    ret = 1e10;
    for(int k=i+1; k<j; k++){
        ret = min(ret , solve(i, k) + solve(k, j) + 1ll * i * j * k);
    }
    return ret;
}

int main() {
    int n; scanf("%d", &n);
    // regular polygon so, doesn't matter how your trangulartion be, and fix 1
    // for(int i = 2; i<n; i++)sum += i*(i+1);
    memset(dp, -1,sizeof(dp));
    cout << solve(1, n);
	return 0;
}