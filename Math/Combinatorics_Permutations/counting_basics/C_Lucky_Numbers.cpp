#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)ans += (1ll << i);
    cout << ans;
}