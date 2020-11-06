#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.begin() + n);
    int mx = v[n - 1], g = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mx - v[i];
        g = __gcd(g, mx - v[i]);
    }
    printf("%lld %d\n", sum / g, g);
}