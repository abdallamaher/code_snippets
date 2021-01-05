#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

ll power(ll n, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)res = (res * n) % mod;
        n = (n * n) % mod;
        p /= 2;
    }
    return res;
}

int main() {
    ll n, m; cin >> n >> m;
    // single present exist in boxs subset eg : 010110
    cout << power(power(2, m) - 1, n) << endl;
    return 0;
}