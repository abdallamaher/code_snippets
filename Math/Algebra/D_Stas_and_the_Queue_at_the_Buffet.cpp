#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        v[i] = { a, b };
    }
    sort(v.begin(), v.end(), [](pair<ll, ll>& a, pair<ll, ll>& b) {
        return a.first - a.second > b.first - b.second;
        });
    ll ans = 0;
    for (int i = 0; i < n;i++) {
        ans += v[i].first * i + v[i].second * (n - i - 1);
    }
    cout << ans << endl;
}