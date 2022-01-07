#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll n, k; cin >> n >> k;
    for (int i = 1;i < k; i++) {
        string s = to_string(n);
        int mn = *min_element(s.begin(), s.end()) - '0';
        int mx = *max_element(s.begin(), s.end()) - '0';
        if (mn == 0)break;
        n += mn * mx;
    }
    cout << n << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}