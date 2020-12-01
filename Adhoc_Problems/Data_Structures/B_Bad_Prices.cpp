#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long 

inline void solve() {
    int n; scanf("%d", &n);
    vector<int> v(n), suf(n + n);
    for (auto& it : v)scanf("%d", &it);
    int ans = 0;
    for (int i = n - 1, mn = 1e9; i >= 0; i--) {
        suf[i] = min(mn, v[i]);
        mn = min(mn, v[i]);
        if (suf[i] < v[i])ans++;
    }
    printf("%d\n", ans);

}

int main() {
    int t; cin >> t;
    while (t--)solve();
}