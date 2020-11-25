#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ll n, m; cin >> n >> m;

    ll i = 0;
    while (i * (i - 1) / 2 < m) i++;
    cout << max(0ll, n - 2 * m) << ' ' << max(0ll, n - i);
    return 0;
}