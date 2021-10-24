#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, m; cin >> n >> m;
    int ar[n + n] = {};
    int p[m + m] = {};
    for (int i = 0; i < n; i++)cin >> ar[i];
    for (int i = 0; i < m; i++) {
        cin >> p[i];
        p[i]--;
    }
    sort(p, p + m);
    for (int i = 0; i < m; i++) {
        int j = i;
        while (j < m && p[j] + 1 == p[j + 1]) j++;
        sort(ar + p[i], ar + p[j] + 2);
        i = j;
    }
    int ok = 1;
    for (int i = 1; i < n; i++) ok &= (ar[i] >= ar[i - 1]);
    cout << (ok ? "YES" : "NO") << endl;
}

int par[110];
int n, m;

int root(int x) {
    if (par[x] == x)return x;
    return par[x] = root(par[x]);
}

void Union(int x, int y) {
    int a = root(x);
    int b = root(y);
    if (a == b)return;
    par[a] = b;
}

void go() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++)par[i] = i;
    int ar[110] = {};
    for (int i = 0; i < n; i++)cin >> ar[i];
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        x--;
        Union(x, x + 1);
    }
    int frq[110][110] = {};
    for (int i = 0; i < n; i++) {
        frq[root(i)][ar[i]]++;
    }
    sort(ar, ar + n);
    int ok = 1;
    for (int i = 0; i < n; i++) {
        ok &= frq[root(i)][ar[i]] > 0;
        frq[root(i)][ar[i]]--;
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)go();
}