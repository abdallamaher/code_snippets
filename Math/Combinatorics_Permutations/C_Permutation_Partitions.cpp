#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    ll sum = 0, ans = 1;
    for (int i = 0, cnt = 0, f = 0; i < n; i++) {
        if (v[i] > n - k) {
            cnt++;
            if (f)ans = cnt * ans;
            sum += v[i];
            ans %= mod;
            cnt = 0;
            f = 1;
        }
        else {
            cnt++;
        }
    }
    printf("%lld %lld\n", sum, ans);
    return 0;
}