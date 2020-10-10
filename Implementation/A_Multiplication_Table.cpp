#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int n, k; cin >> n >> k;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (k % i == 0 && k / i <= n)++ans;
    }
    cout << ans;
    return 0;
}