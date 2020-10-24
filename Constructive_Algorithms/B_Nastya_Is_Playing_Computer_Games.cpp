#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {

    int n, k; cin >> n >> k;
    cout << (2 * n + 1) + (n - 1) + min(k - 1, n - k);
    
    return 0;
    if (k > (n + 1) / 2)k = n - k + 1;
    ll ans = 0;
    if (k != 1) {
        ans = 6 + 3 * (k - 2);
        ans += (k - 1) + 3 * (n - k);
    }
    if (k == 1) {
        ans = 6;
        k = 2;
        ans += 3 * (n - k);
    }
    cout << ans << endl;
    return 0;
}