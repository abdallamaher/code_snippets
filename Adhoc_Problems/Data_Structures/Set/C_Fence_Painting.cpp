#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, m; cin >> n >> m;
    multiset<pair<int, int>> equal, need, recolor;
    vector<int> a(n);
    for (int i = 0;i < n; i++)scanf("%d", &a[i]);
    for (int i = 0;i < n; i++) {
        int x; scanf("%d", &x);
        if (x == a[i])equal.insert({ x, i });
        else need.insert({ x, i });
    }
    vector<int> data(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &data[i]);
    }

    int ok = 1;
    vector<int> ans;
    for (int i = m - 1; i >= 0; i--) {
        int color = data[i];
        auto p = need.lower_bound({ color, -1 });
        if (p != need.end() && p->first == color) {
            ans.push_back(p->second);
            need.erase(p);
            recolor.insert(*p);
            equal.insert(*p);
            continue;
        }
        if (recolor.size()) {
            p = recolor.begin();
            ans.push_back(p->second);
            continue;
        }
        p = equal.lower_bound({ color, -1 });
        if (p != equal.end() && p->first == color) {
            recolor.insert(*p);
            ans.push_back(p->second);
            continue;
        }
        ok = 0;
    }

    if (ok && need.empty()) {
        puts("YES");
        reverse(ans.begin(), ans.end());
        for (auto it : ans)printf("%d ", it + 1);
        puts("");
    }
    else {
        puts("NO");
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}