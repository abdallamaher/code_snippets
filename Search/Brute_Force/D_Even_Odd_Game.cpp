#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    string ans[] = { "Tie", "Alice", "Bob", "" };
    int n; cin >> n;
    vector<ll> odd, even;
    for (int i = 0; i < n; i++) {
        ll x; scanf("%lld", &x);
        if (x & 1) odd.push_back(x);
        else even.push_back(x);
    }
    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    n = even.size(); int m = odd.size();
    ll sum1 = 0, sum2 = 0;
    int i = 0, j = 0, f = 0;
    while (i < m || j < n) {
        if (f == 0) {
            if (i < m && j < n && even[j] > odd[i])sum1 += even[j], j++;
            else if (j < n && i >= m) sum1 += even[j], j++;
            else i++;
        }
        else {
            if (i < m && j < n && even[j] < odd[i])sum2 += odd[i], i++;
            else if (i < m && j >= n) sum2 += odd[i], i++;
            else j++;
        }
        f = 1 - f;
    }
    int ok;
    if (sum1 > sum2)ok = 1;
    else if (sum1 == sum2)ok = 0;
    else ok = 2;
    cout << ans[ok] << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}