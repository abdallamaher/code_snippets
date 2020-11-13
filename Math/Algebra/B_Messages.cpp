#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int n, st, d, inc, t;scanf("%d%d%d%d%d", &n, &st, &d, &inc, &t);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += st - d * (t - v[i]);
        ans += inc * (t - v[i]);
    }
    cout << max(1ll * n * st, ans) << endl;
    return 0;
}