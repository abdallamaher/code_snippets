#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int Mod = 1e9 + 7;

ll pow_mod(ll n, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)res = (res * n) % Mod;
        p >>= 1;
        n = (n * n) % Mod;
    }
    return res;
}

int main(void) {
    ll x, k;
    scanf("%lld%lld", &x, &k);
    if (x == 0) {
        printf("0\n");
        return 0;
    }
    ll a = (pow_mod(2, k + 1) * (x % Mod)) % Mod;
    ll b = pow_mod(2, k);
    printf("%lld\n", ((a - b + Mod) % Mod + 1) % Mod);
    return 0;
}