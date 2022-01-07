#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v;

void build() {
    int i = 1;
    v.push_back(0);
    while (v.back() <= (int)1e9) {
        v.push_back(v.back() + 3 * i - 1);
        i++;
    }
}

inline void solve() {
    int n; cin >> n;
    int ans = 0;
    while (1) {
        auto p = upper_bound(v.begin(), v.end(), n) - v.begin() - 1;
        if (v[p] == 0)break;
        n -= v[p];
        ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    build();
    while (t--)solve();
}