#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int OO = (int)1e9;
const int N = 1e5 + 5;
 
 
int n,x, mx;
int ar[N];
ll dp[N];
 
 
ll go(int i = 0){
    if(i > mx) {
        return 0;
    }
    if(~dp[i]) return dp[i];
 
    long long a, b;
    // leave
    b = go(i + 1) * 1ll;
    // pick
    a = go(i + 2) * 1ll + (1ll * i * ar[i]);
 
//    printf("%lld %lld\n", a, b);
    return dp[i] = max(a, b);
}
int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &x);
        ar[x]++;
        mx = max(x, mx);
    }
    printf("%lld", go());
    return 0;
}
 
 
 
 
 