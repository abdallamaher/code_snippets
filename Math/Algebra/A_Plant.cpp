#include <bits/stdc++.h>
using namespace std;
#define ll long long    
#define mod 1000000007

ll pw(ll n, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)res = (res * n) % mod;
        n = (n * n) % mod;
        p /= 2;
    }
    return res;
}

int main() {
    ll n; cin >> n;
    
    if (n == 0)cout << 1 << endl;
    else cout << (pw(2, 2 * n - 1) + pw(2, n - 1)) % mod << endl;
    return 0;
}