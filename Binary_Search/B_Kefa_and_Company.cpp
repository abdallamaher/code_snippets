#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, d;
ll mx = 0;

int main() {
    cin >> n >> d;
    // first money
    // second friendship
    vector< pair<ll, ll> > ar(n + 1);
    for (int i = 1;i <= n; i++) {
        scanf("%lld %lld", &ar[i].first, &ar[i].second);
    }
    sort(ar.begin(), ar.end());
    for (int i = 1;i <= n; i++) {
        ar[i].second += ar[i - 1].second;
    }

    for (int i = 1; i <= n; i++) {
        auto p = upper_bound(ar.begin(), ar.end(), make_pair(ar[i].first + d, -1ll));
        mx = max(mx, ar[p - ar.begin() - 1].second - ar[i - 1].second);
    }
    cout << mx << endl;
}