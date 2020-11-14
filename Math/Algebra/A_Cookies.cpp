#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e6 + 3;


int main() {
    int n; cin >> n;
    ll ans = 1;
    for (int i = 2; i <= n; i++)ans = (ans * 3) % mod;
    cout << ans;
    return 0;
}