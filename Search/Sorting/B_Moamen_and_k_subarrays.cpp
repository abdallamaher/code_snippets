#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; cin >> n >> k;
    map<int, int> pre;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pre[v[i]] = v[i - 1];
    }
    sort(v.begin(), v.end());
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] != pre[v[i]])cnt++;
    }
    cout << (cnt <= k ? "Yes" : "No") << endl;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}