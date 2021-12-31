#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T, n;
int p[105], Rank[105];
double x[105], y[105];

struct edge
{
    int u;
    int v;
    double dis;

    bool operator<(const edge& other) const
    {
        return dis < other.dis;
    }
} Edges[105 * 105];

double getDistance(int i, int j) {
    double xD = (x[i] - x[j]);
    double yD = (y[i] - y[j]);
    return sqrt(xD * xD + yD * yD);
}

int find_parent(int n) {
    vector<int> v;
    while (p[n] != n) {
        v.push_back(n);
        n = p[n];
    }
    for (auto& it : v)p[it] = n;
    return n;
}

int isUnioned(int u, int v) {
    u = find_parent(u);
    v = find_parent(v);
    if (u == v)return 1;
    if(Rank[u] < Rank[v]) swap(u, v);   // u always big
    p[v] = u;                           // u is parent
    Rank[u] += Rank[u] == Rank[v];      // u new rank
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while (T--) {
        for (int i = 0;i < 105; i++)p[i] = i, Rank[i] = 0;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        int cnt = 0;
        for (int i = 0;i < n; i++) {
            for (int j = 0; j < i;j++) {
                Edges[cnt] = { i, j, getDistance(i, j) };
                cnt++;
            }
        }
        sort(Edges, Edges + cnt);
        double ans = 0;
        for (int i = 0; i < cnt; i++) {
            if (isUnioned(Edges[i].u, Edges[i].v) == 0) {
                ans += Edges[i].dis;
            }
        }
        cout << fixed << setprecision(2) << ans << endl;
        if (T)cout << endl;
    }
}