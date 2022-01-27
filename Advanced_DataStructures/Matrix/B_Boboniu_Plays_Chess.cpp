#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, sx, sy;
void print(int a, int b) {
    if ((a == sx || a == 1) && b == sy)return;
    cout << a << ' ' << b << endl;
}

inline void solve() {
    cin >> n >> m >> sx >> sy;
    cout << sx << ' ' << sy << endl;
    if (sx > 1) {
        cout << 1 << ' ' << sy << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            for (int j = 1; j <= m; j++)print(i, j);
        }
        else {
            for (int j = m; j >= 1; j--)print(i, j);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}