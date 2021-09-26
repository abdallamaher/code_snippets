#include <bits/stdc++.h>
using namespace std;
#define ll long long

string a, b;
const int N = 3e3 + 5;
int dp[N][N];

int go(int i, int j) {
    if (i == a.size() || j == b.size())return 0;
    int& ret = dp[i][j];
    if (~ret)return ret;

    if (a[i] == b[j])return ret = go(i + 1, j + 1) + 1;
    int aa = go(i + 1, j);
    int bb = go(i, j + 1);

    return ret = max(aa, bb);
}

void build(int i, int j) {
    if (i == a.size() || j == b.size())return;
    int& ret = dp[i][j];

    if (a[i] == b[j]) {
        if (ret == go(i + 1, j + 1) + 1)
            cout << a[i];
        return build(i + 1, j + 1);
    }
    if (ret == go(i + 1, j)) {
        build(i + 1, j);
    }
    else {
        build(i, j + 1);
    }
}

inline void solve() {
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    go(0, 0);
    build(0, 0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}