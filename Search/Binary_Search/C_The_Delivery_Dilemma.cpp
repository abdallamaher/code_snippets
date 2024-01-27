#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll n; scanf("%lld", &n);
    pair<ll, ll> ar[n];
    for (int i = 0; i < n;i++)scanf("%lld", &ar[i].first);
    for (int i = 0; i < n;i++)scanf("%lld", &ar[i].second);
    ll ans = 0;
    ll st = 0, en = 1e9, mid;
    while (st < en) {
        mid = (st + en) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++) if (ar[i].first > mid) {
            sum += ar[i].second;
        }
        if(sum <= mid) en = mid;
        else st = mid +  1;
    }
    cout << en << endl;
}

inline void go() {
    ll n; scanf("%lld", &n);
    ll sum = 0;
    pair<ll, ll> ar[n];
    for (int i = 0; i < n;i++)scanf("%lld", &ar[i].first);
    for (int i = 0; i < n;i++)scanf("%lld", &ar[i].second), sum += ar[i].second;
    sort(ar, ar + n);
    for (int i = 1; i < n; i++)ar[i].second += ar[i - 1].second;
    ll ans = sum;
    for (int i = 0;i < n; i++) {
        ans = min(ans, max(ar[i].first, sum - ar[i].second));
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}