#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int pow(int n, int p, int mod = 998244353) {
    int res = 1;
    while (p) {
        if (p & 1)res = (1ll * res * n) % mod;
        n = (1ll * n * n) % mod;
        p /= 2;
    }
    return res;
}

int main() {
    int n, m; cin >> n >> m;
    int res = 1;
    int mod = 998244353;
    while (n--)res = (res * 2) % mod;
    while (m--)res = (res * 2) % mod;
    cout << res;

    return 0;

    cout << pow(2, n + m);
    return 0;
}