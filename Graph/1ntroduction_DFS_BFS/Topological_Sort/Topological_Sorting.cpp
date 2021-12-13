#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e4 + 5;
vector<int> adj[N];
int deg[N];
int n, m;
vector<int> ans;

bool kahn() {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) if (deg[i] == 0)
        q.push(i);

    while (q.size()) {
        int cur = q.top();
        q.pop();
        ans.push_back(cur);

        for (int& child : adj[cur]) {
            deg[child]--;
            if (deg[child] == 0) {
                q.push(child);
            }
        }
    }

    return (int)ans.size() == n;
}

inline void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    if (kahn() == 0) {
        cout << "Sandro fails." << endl;
    }
    else {
        for (auto& it : ans)cout << it << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}