#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
vector<int> adj[N];

int main() {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        int x; scanf("%d", &x);
        adj[x].push_back(i);
    }
    int ok = 1;
    for (auto it : adj) {
        int x = it.size();
        if (!x)continue;

        for (auto e : it) if (adj[e].size())x--;
        if (x < 3)ok = 0;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}   