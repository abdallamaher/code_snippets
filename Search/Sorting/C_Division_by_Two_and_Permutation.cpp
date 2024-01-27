#include <bits/stdc++.h>
using namespace std;
#define ll long long

int p[55];
int n;

void go(int x) {
    if (x <= 0)return;
    if (x <= n && !p[x]) {
        p[x] = 1;
        return;
    }
    go(x / 2);
}

inline void solve() {
    for (int i = 1; i <= n; i++)p[i] = 0;

    cin >> n;

    vector<int> v(n);
    for (int i = 0;i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = n - 1;i >= 0;i--)go(v[i]);
    
    int ok = 1;
    for (int i = 1; i <= n; i++) if (!p[i])ok = 0;
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}