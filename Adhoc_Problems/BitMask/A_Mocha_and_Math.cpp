#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> ar(n);
    for (auto& it : ar)cin >> it;
    // int ans = 0;
    // for (int i = 0; i < 30; i++)ans |= (1 << i);
    int ans = ar[0];
    for (int i = 0; i < n; i++)ans &= ar[i];
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}