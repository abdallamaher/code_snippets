#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
int p[N];

int find_parent(int n) {
    vector<int> v;
    while (p[n] != n) {
        v.push_back(n);
        n = p[n];
    }
    for (auto& it : v)p[it] = n;
    return n;
}

int Union(int u, int v) {
    u = find_parent(u);
    v = find_parent(v);
    if (u == v)return 0;
    p[u] = v;
    return 1;
}

inline void solve() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++)p[i] = i;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        auto p = st.lower_bound(x);
        if (p == st.end()) {
            st.insert(x);
        }
        else {
            int mx;
            while (p != st.end()) {
                mx = *p;
                Union(*p, x);
                p = st.erase(p);
            }
            st.insert(mx);
        }
    }
    int ans = 0;
    for (int i = 1;i <= n; i++)if (p[i] == i)ans++;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}