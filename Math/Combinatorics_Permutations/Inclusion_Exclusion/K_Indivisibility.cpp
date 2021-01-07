#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll n; cin >> n;
    ll ans = n;
    // inclusion exclusion
    // 2, 3, 5, 7

    ans -= n / 2 + n / 3 + n / 5 + n / 7;
    ans += n / (2 * 3) + n / (2 * 5) + n / (2 * 7) + n / (3 * 5) + n / (3 * 7) + n / (5 * 7);
    ans -= n / (2 * 3 * 5) + n / (2 * 3 * 7) + n / (2 * 5 * 7) + n / (3 * 5 * 7);
    ans += n / (2 * 3 * 5 * 7);
    
    cout << ans << endl;
}