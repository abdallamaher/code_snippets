#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    int cnt = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > 1) {
            cnt = i + 1;
            break;
        }
    }
    if (cnt % 2 || (cnt == 0 && n & 1))cout << "First\n";
    else cout << "Second\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}