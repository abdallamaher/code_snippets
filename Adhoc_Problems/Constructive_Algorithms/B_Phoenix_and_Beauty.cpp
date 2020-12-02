#include <bits/stdc++.h>
using namespace std;
#define ll long long 

inline void solve() {
    int n, k; scanf("%d %d", &n, &k);
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        s.insert(x);
    }

    if (s.size() > k) {
        puts("-1");
        return;
    }

    vector<int> ans;
    for (int i = 1; i <= n && s.size() < k; i++) {
        if (s.find(i) == s.end()) {
            s.insert(i);
        }
    }
    while (n--) {
        for (auto it : s)ans.push_back(it);
    }
    printf("%d\n", ans.size());
    for (auto it : ans)printf("%d ", it);
    puts("");
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}