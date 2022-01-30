#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    map<int, vector<int> > mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[x].push_back(i);
    }
    vector<int> v;
    vector<int> ans;
    for (auto& it : mp) {
        sort(it.second.rbegin(), it.second.rend());
        for (auto& e : it.second) {
            int cnt = 0;
            for (auto& x : v)if (e > x)cnt++;
            if(e-cnt != n)ans.push_back(e - cnt);
            v.push_back(e);
        }
    }
    printf("%d\n", ans.size());
    for (auto& it : ans)printf("%d %d 1\n", it, n);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}