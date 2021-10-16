#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    ll mx = 1ll * v[0] * v[1] * v[n - 1] * v[n - 2] * v[n - 3];
    mx = max(mx, 1ll * v[n - 1] * v[n - 2] * v[n - 3] * v[n - 4] * v[n - 5]);
    mx = max(mx, 1ll * v[0] * v[1] * v[2] * v[3] * v[n - 1]);
    cout << mx << endl;
}

void go() {
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    ll mx = -8e18;
    for (int i = 0;i < 6;i++) {
        ll tmp = 1;
        for (int j = 0; j < i; j++)tmp *= v[j];
        for (int j = 0; j < 5 - i;j++)tmp *= v[n - j - 1];
        mx = max(mx, tmp);
    }
    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) go();
}