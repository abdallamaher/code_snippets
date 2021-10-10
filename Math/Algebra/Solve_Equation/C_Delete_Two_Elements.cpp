#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    int ar[n + n] = {};
    map<int, int> mp;
    ll sum = 0;
    for (int i = 0;i < n; i++) {
        cin >> ar[i];
        mp[ar[i]]++;
        sum += ar[i];
    }
    if ((2 * sum) % n) {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int a = ar[i];
        int b = sum * 2 / n - a;
        mp[a]--;
        ans += mp[b];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}