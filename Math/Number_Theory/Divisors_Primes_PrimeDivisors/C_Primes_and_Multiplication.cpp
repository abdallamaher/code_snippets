#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
vector<ll> fac;
ll x, n;

ll power(ll n, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)res = (res * n) % mod;
        p >>= 1;
        n = (n * n) % mod;
    }
    return res;
}

void prime_fac(ll x) {
    for (ll i = 2;i * i <= x;i++) {
        if (x % i)continue;
        fac.push_back(i);
        while (x % i == 0)x /= i;
    }
    if (x > 1)fac.push_back(x);
}

int main() {
    cin >> x >> n;
    prime_fac(x);
    ll ans = 1;
    for (int i = 0;i < fac.size();i++) {
        ll N = n;
        ll tmp = 0;
        /*
        how many numbers under N can divide fac[i]
        eg: 6 2 
        6 4 2 can divide 2
        if we divide all by 2
        3 2 1
        so max num could content 2 as prime_fac is 6/2
        */
        while (N >= fac[i]) {
            N /= fac[i];
            tmp += N;
        }
        ans = (ans * power(fac[i], tmp)) % mod;
    }
    cout << ans << endl;
}