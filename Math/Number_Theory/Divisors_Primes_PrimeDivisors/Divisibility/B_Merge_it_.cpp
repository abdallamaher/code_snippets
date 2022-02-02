#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> ar(3);
    for (int i = 0;i < n; i++) {
        int x; cin >> x;
        ar[x % 3]++;
    }
    int x = min(ar[1], ar[2]);
    int ans = ar[0] + x;
    ar[1] -= x;
    ar[2] -= x;
    cout << ans + ar[1] / 3 + ar[2] / 3 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}