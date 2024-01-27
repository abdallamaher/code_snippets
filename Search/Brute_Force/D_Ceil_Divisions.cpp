#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v;
    for (ll i = n - 1; i >= 2; i--) {
        ll j = i - 1;
        if (j * j > n) {
            v.push_back({ i, n });
        }
        else {
            v.push_back({ n, i });
            v.push_back({ n, i });
            n = i;
        }
    }
    cout << v.size() << endl;
    for (auto it : v)printf("%d %d\n", it.first, it.second);
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}