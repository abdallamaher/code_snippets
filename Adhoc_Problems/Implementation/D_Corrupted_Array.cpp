#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    n += 2;
    vector<ll> ar(n), sum(n);
    for (auto& it : ar)cin >> it;
    sort(ar.begin(), ar.end());
    sum[0] = ar[0];
    for (int i = 1; i < n; i++) {
        sum[i] += sum[i - 1] + ar[i];
    }
    // for (int i = 0; i < n; i++)cout << sum[i] << ' ';
    // cout << endl;
    int m = n - 2;
    if (sum[m - 1] == ar[n - 2] || sum[m - 1] == ar[n - 1]) {
        for (int i = 0; i < m; i++)cout << ar[i] << ' ';
        cout << endl;
        return;
    }
    int p = 0;
    for (int i = 0;i < m; i++) {
        ll tmp = sum[m - 1] - ar[i] + ar[n - 2];
        // cout << sum[m - 1] << ' ' << ar[i] << ' ' << ar[n - 2] << endl;
        if (tmp == ar[n - 1]) {
            swap(ar[i], ar[n - 2]);
            p = 1;
            break;
        }
    }
    if (p == 0) {
        cout << "-1\n";
    }
    else {
        for (int i = 0; i < m; i++)cout << ar[i] << ' ';
        cout  << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}