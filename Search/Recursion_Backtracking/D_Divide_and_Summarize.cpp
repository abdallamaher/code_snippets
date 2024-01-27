#include <bits/stdc++.h>
using namespace std;
#define ll long long

void build_ans(vector<int>& v, set<ll>& s) {
    ll sum = 0;
    for (auto it : v)sum += it;
    s.insert(sum);

    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    if (mx == mn)return;

    int mid = (mx + mn) / 2;
    vector<int> l, r;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > mid)l.push_back(v[i]);
        else r.push_back(v[i]);
    }

    build_ans(r, s);
    build_ans(l, s);
}

inline void solve() {
    int n, q; scanf("%d %d", &n, &q);
    vector<int> v(n);
    for (int i = 0; i < n; i++)scanf("%d", &v[i]);
    set<ll> s;
    build_ans(v, s);
    while (q--) {
        ll Q; scanf("%lld", &Q);
        puts(s.count(Q) ? "Yes" : "No");
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}