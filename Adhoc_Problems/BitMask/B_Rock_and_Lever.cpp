#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double 


int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        vector<int> v(32);
        for(int i=0; i<n; i++){
            int x; scanf("%d", &x);
            v[__builtin_clz(x)]++;
        }
        ll ans = 0;
        for(int i=0; i<32; i++){
            ans += 1ll * v[i] * (v[i] - 1) / 2;
        }
        printf("%lld\n", ans);
    }

    return 0;
}