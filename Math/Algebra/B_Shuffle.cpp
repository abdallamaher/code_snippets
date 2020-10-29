#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, x, q; scanf("%d%d%d", &n, &x, &q);
    vector<pair<int, int>> v;
    v.push_back({ x, x });
    while (q--) {
        int l, r;scanf("%d %d", &l, &r);
        for (int i = 0; i < v.size(); i++) {
            if (l > v[i].second || v[i].first > r)continue;
            v.push_back({ l, r });
            break;
        }
    }
    sort(v.begin(), v.end());
    ll sum = v[0].second - v[0].first + 1;
    //cout << v[0].first << ' ' << sum << '\n';
    for (int i = 1; i < v.size(); i++) {
        if (v[i].second - v[i - 1].second > 0)sum += v[i].second - v[i - 1].second;
        else v[i].second = v[i - 1].second;
    }
    cout << sum << '\n';
}

inline void go() {
    int n, x, q; scanf("%d%d%d", &n, &x, &q);
    int l = x, r = x;
    while (q--) {
        int a, b;scanf("%d %d", &a, &b);
        // if (l > b || a > r)continue;
        if (max(a, l) <= min(r, b))
            l = min(l, a), r = max(r, b);
    }

    cout << r - l + 1 << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) go();
    return 0;
}