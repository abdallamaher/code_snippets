#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int OO = (int)1e9;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n , k, d;
int dp[105][2];
 
int go(int rem, int f){
    if(rem < 0) {
        return 0;
    }
    if(rem == 0){
//        printf("*** %d\n", f);
        if(f) return 1;
        return 0;
    }
 
    if(~dp[rem][f])return dp[rem][f];
 
    int ans = 0;
    for(int i=1; i<=k; ++i){
        if(d <= i) ans = (ans + go(rem - i, 1)) % mod;
        else ans = (ans + go(rem - i, f)) % mod;
//        printf("ans %d\n", ans);
    }
 
    return dp[rem][f] = ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> d;
 
    cout << go(n, 0);
    return 0;
}
 
 