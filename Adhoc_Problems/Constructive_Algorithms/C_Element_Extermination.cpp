#include <bits/stdc++.h>
using namespace std;
#define ll long long 

inline void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    puts(v[n - 1] > v[0] ? "YES" : "NO");
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}