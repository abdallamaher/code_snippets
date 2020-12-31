#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;

inline void solve() {
    int n;cin >> n;
    int wei[n + n] = {};
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", wei + i);
        sum += wei[i];
    }
    int degree[n + n] = {};
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        degree[u]++;
        degree[v]++;
    }
    set<pair<int, int>> st;
    for (int i = 1; i <= n; i++) {
        st.insert({ wei[i], i });
    }
    cout << sum << ' ';
    while (st.size()) {
        auto cur = *st.rbegin();
        st.erase(*st.rbegin());
        int cnt = degree[cur.second];
        while (--cnt) {
            sum += cur.first;
            cout << sum << ' ';
        }
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}