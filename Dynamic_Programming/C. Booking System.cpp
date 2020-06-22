#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
const int N = 1e3 + 5;
pair<pair<int, int>, int> people[1005];
pair<int, int> table[N];
#define f first
#define s second
pair<int, int> nxt[N][N];
int dp[N][N];

int solve(int p=n, int t=m) {
    //printf("%d %d\n", p, t);
    if (p<0 || t<0)return 0;
    int& ret = dp[p][t];
    if (~ret)return ret;
    int a, b, c = 0;
    a = solve(p - 1, t);
    b = solve(p, t - 1);
    c = solve(p - 1, t - 1) + ((table[t].f >= people[p].f.f) ? people[p].f.s : 0);
    ret = max(a, max(c, b));

    if (ret == a) {
        nxt[p][t] = { p - 1,t };
    }
    else if (ret == b) {
        nxt[p][t] = { p, t - 1 };
    }
    else if (ret == c) {
        nxt[p][t] = { p - 1, t - 1 };
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        people[i] = { {u, v}, i };
    }
    sort(people, people + n);
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        table[i] = { x, i };
    }
    sort(table, table + m);
    memset(dp, -1, sizeof(dp));
    int s = solve();
    cerr << solve() << endl;
	
    vector<pair<int, int>> v;
    pair<int, int> cur = { n, m };
    while (cur.f >= 0 && cur.s >= 0) {
        pair<int, int> p = nxt[cur.f][cur.s];
        if (p.first == cur.first - 1 && p.second == cur.second - 1 &&
            table[cur.s].f >= people[cur.f].f.f)
            v.push_back({ people[cur.f].s, table[cur.s].s });

        cur = nxt[cur.f][cur.s];
    }
    cout << v.size() << " " << s << endl;
    sort(v.begin(), v.end());
    for (auto it : v) {
        cout << it.first+1 << ' ' << it.second+1 << endl;
    }
    return 0;
}

