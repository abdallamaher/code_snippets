#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> v(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s[i] = v[i];
    }
    sort(s.begin(), s.end());
    int mn = s[0];
    for (int i = 0; i < n;i++) {
        if (v[i] != s[i] && v[i] % mn) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}