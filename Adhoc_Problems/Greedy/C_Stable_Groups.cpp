#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
ll ar[N];

inline void solve() {
    ll n, k, x; cin >> n >> k >> x;
    for (int i = 0; i < n; i++)cin >> ar[i];
    sort(ar, ar + n);
    vector<ll> v;
    for (int i = 1;i < n; i++) {
        v.push_back(max(0ll, (ar[i] - ar[i - 1] - 1) / x));
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= k)k -= v[i];
        else sum++;
    }
    cout << sum + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}