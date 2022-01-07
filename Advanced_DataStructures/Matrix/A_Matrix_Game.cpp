#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int g[55][55];

int check(int r, int c) {
    int ret = 1;
    for (int x = 0; x < m; x++) {
        if (g[r][x])ret = 0;
    }
    for (int x = 0; x < n; x++) {
        if (g[x][c])ret = 0;
    }
    return ret;
}

inline void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    while (1) {
        int ok = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 0)ok += check(i, j);
                if (ok) {
                    g[i][j] = 1;
                    break;
                }
            }
            if (ok)break;
        }
        if (ok)ans = 1 - ans;
        else break;
    }
    if (ans == 0)cout << "Vivek" << endl;
    else cout << "Ashish" << endl;
}

void go() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int a = 0, b = 0;
    for (int r = 0; r < n; r++) {
        int cnt_r = 0;
        for (int c = 0; c < m; c++) {
            cnt_r += g[r][c];
        }
        a += !bool(cnt_r);
    }
    for (int c = 0; c < m; c++) {
        int cnt_c = 0;
        for (int r = 0; r < n; r++) {
            cnt_c += g[r][c];
        }
        b += !bool(cnt_c);
    }
    if (min(a, b) % 2 == 0)cout << "Vivek" << endl;
    else cout << "Ashish" << endl;
}

void run() {
    cin >> n >> m;
    set<int> a, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j]) {
                a.insert(i);
                b.insert(j);
            }
        }
    }

    if (min(n - a.size(), m - b.size()) % 2 == 0)cout << "Vivek" << endl;
    else cout << "Ashish" << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)run();
}