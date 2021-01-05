#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5, mod = 1e9 + 7;

int n, m, cnt;
int ar[N], vis[N];
vector<int> R[N], L[N], groups[N];
stack<int> st;

void dfs1(int i) {
    vis[i] = 1;
    for (auto it : R[i]) {
        if (!vis[it])dfs1(it);
    }
    st.push(i);
}

void dfs2(int i) {
    vis[i] = 1;
    for (auto it : L[i]) {
        if (!vis[it])dfs2(it);
    }
    groups[cnt].push_back(i);
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];

    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        R[u].push_back(v);
        L[v].push_back(u);
    }

    // start kosaraku's algorithms for SCC
    for (int i = 0; i < n; i++) {
        if (!vis[i])dfs1(i);
    }

    memset(vis, 0, sizeof vis);
    while (st.size()) {
        int v = st.top();
        st.pop();
        if (!vis[v]) {
            dfs2(v);
            cnt++;
        }
    }
    ll count = 1, sum =0;
    for (auto it : groups) {

        if (it.size() == 0)break;
        int mn = 1e9, mnN = 0;
        for (auto x : it) {
            if (ar[x] < mn) {
                mn = ar[x];
                mnN = 1;
            }
            else if (ar[x] == mn)mnN++;
        }
        sum += mn;
        count = (count * mnN) % mod;
    }
    cout << sum << ' ' << count;
    return 0;
}
