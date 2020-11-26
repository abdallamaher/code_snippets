#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> v(n);
        for (auto& it : v)scanf("%d", &it);
        ll sum = 0;
        for (int i = 1; i < n; i++) {
            if(v[i-1] > v[i])
                sum += v[i-1] - v[i];
        }
        cout << sum << '\n';
        continue;

        int mn = 1e9 + 5, p = v[0];
        ll ans = 0;
        for (int i = 1; i < n; i++) {
            if (v[i - 1] > v[i])mn = min(mn, v[i]);
            if (mn != 1e9 + 5 && (v[i - 1] <= v[i] || i == n - 1)) {
                ans += p - mn;
                mn = 1e9 + 5;
                p = v[i];
            }
            else if (v[i - 1] <= v[i]) p = v[i];

            // cout << i << ' ' << p << ' ' << mn << ' ' << ans <<  endl;
        }
        cout << ans << '\n';
    }
    return 0;
}