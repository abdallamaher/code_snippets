#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int b, k,n; scanf("%d%d%d", &b, &k, &n);
    int f = 0;
    for(int i=1; i<=100000; i++){
        ll a = (1ll * i * k) - b;
        if(a > 0 && b + a <= n)printf("%lld ", a), f = 1;
    }
    if(!f)puts("-1");
	return 0;
}