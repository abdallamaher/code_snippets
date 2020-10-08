#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> v(n);
    for (auto& it : v)scanf("%d", &it);
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        int x = v[i] - v[0];
        if (x % k)return cout << -1, 0;
        ans += x / k;
    }
    printf("%lld\n", ans);
    return 0;
}