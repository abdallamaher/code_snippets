#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; scanf("%d", &n);
    vector<int> v(n + 5), ans;
    for (int i = 1; i <= n; i++)scanf("%d", &v[i]);
    sort(v.begin() + 1, v.begin() + n + 1);
    for (int i = 1, j = n; i <= n / 2; i++, j--) {
        ans.push_back(v[j]);
        ans.push_back(v[i]);
    }
    if (n & 1)ans.push_back(v[(n + 1) / 2]);
    reverse(ans.begin(), ans.end());
    for (auto it : ans)printf("%d ", it);
    puts("");
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}