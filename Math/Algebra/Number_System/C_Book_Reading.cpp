#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll n, m; cin >> n >> m;
    n = n / m;
    ll sum = 0;
    vector<int> ar(10);
    for (int i = 0; i < 10; i++) ar[i] = (i + 1) * m % 10;
    for (int i = 0; i < n % 10; i++)sum += ar[i];
    cout << sum + n / 10 * accumulate(ar.begin(), ar.end(), 0ll) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}