#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    int pos = 2e9;
    int ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] <= 0)ans++;
        else pos = min(pos, v[i]);
    }
    sort(v.begin(), v.end());

    for (int i = 1;i < v.size(); i++) {
        if (v[i] <= 0 && v[i] - v[i - 1] < pos)pos = 0;
    }
    if (pos == (int)2e9) pos = 0;
    cout << ans + bool(pos) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}
/*
1
1
-1
*/