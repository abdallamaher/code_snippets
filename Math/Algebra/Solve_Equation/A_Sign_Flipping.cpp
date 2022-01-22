#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (i % 2 == 0)cout << abs(x) << ' ';
        else cout << -abs(x) << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}