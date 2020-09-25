#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    // 1 2 1 4 1 2 1 8  1 2 1 4 1 2 1
    int t; scanf("%d", &t);
    while(t--){
        ll n; scanf("%lld", &n);
        ll cnt = 0, ans = 0;
        for(int i=0; i<31; i++){
            cnt = 2 * cnt + (1ll << i) * (1ll << i);
            if(cnt <= n){
                ans++;
                n-=cnt;
            }
        }
        printf("%lld\n", ans);
    }
    
	return 0;
}