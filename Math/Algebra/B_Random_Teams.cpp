#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll go(ll x) {
    ll res = x * (x - 1) / 2;
    return res;
}

int main() {
    ll n, m; cin >> n >> m;
    ll mn = 0;
    mn = (m - (n % m)) * go(n / m);
    mn += (n % m) * go(n / m + 1);


    ll mx = n - m;
    mx = go(mx + 1);
    cout << mn << ' ' << mx;
    return 0;
}