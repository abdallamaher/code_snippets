#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n + 5);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        ll sum = 0, ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] < 0)sum += v[i];
            else {
                ll x = min(-sum, 1ll * v[i]);
                v[i] -= x;
                sum += x;
            }
            if (v[i] > 0)ans += v[i];
        }
        cout << ans << '\n';
    }
    return 0;
}