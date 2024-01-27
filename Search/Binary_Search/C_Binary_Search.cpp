#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int mod = 1e9 + 7;
int main() {
    int n, x, p; cin >> n >> x >> p;
    int l = 0, r = n;
    vector<int> search;
    while (l < r) {
        int mid = (l + r) >> 1;
        search.push_back(mid);
        if (mid <= p)l = mid + 1;
        else r = mid;
    }
    ll ans = 1;
    int big = n - x, small = x - 1;
    for (int i = 0; i < search.size(); i++) {
        if (search[i] < p) {
            ans *= small;
            ans %= mod;
            small--;
        }
        else if (search[i] > p) {
            ans *= big;
            ans %= mod;
            big--;
        }
    }
    // cout << small << ' ' << big << endl;
    for (ll i = 1; i <= small + big; i++) {
        ans *= i;
        if (ans > mod)ans %= mod;
    }
    cout << ans << endl;
    return 0;
}