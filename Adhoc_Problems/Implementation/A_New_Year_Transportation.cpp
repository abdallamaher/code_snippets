#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int n, t, ok;
const int N = 1e5 + 5;
vector<int> adj[N];
void dfs(int i = 1) {
    if (i == t) ok = 1;
    for (auto it : adj[i]) dfs(it);
}

int main() {
    cin >> n >> t;
    // for (int i = 1; i < n; i++) {
    //     int x; scanf("%d", &x);
    //     adj[i].push_back(i + x);
    // }
    // dfs();
    // puts(ok ? "YES" : "NO");
    vector<int> ar(N, 0);
    for (int i = 1; i < n; i++) {
        int x;  scanf("%d", &x);
        ar[i] = i + x;
    }
    int p = 1;
    while (p < t) {
        p = ar[p];
    }
    puts(p == t ? "YES" : "NO");
    return 0;
}