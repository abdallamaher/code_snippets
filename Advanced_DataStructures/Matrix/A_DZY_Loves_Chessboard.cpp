#include <bits/stdc++.h>
using namespace std;
#define ll long long


inline void solve() {
    int n, m; cin >> n >> m;
    char g[n][m] = {};
    vector < vector<pair<int, int>> > adj(n + m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '.')adj[i + j].push_back({ i, j });
        }
    }
    int f = 0;
    for (int i = 0; i < adj.size(); i++) {
        for (auto& it : adj[i]) {
            if (f)g[it.first][it.second] = 'W';
            else g[it.first][it.second] = 'B';
        }
        f = 1 - f;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << g[i][j];
        cout << endl;
    }
}

void go() {
    int n, m; cin >> n >> m;
    for (int i = 0;i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                if ((i + j) & 1) s[j] = 'W';
                else s[j] = 'B';
            }
        }
        cout << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)go();
}