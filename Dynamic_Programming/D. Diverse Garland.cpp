#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int n;
string s;
int dp[N][5];
pair<int,int> nxt[N][5];

int solve(int i = 0, int p = 3) {
    if (i == n)return 0;
    int& ret = dp[i][p];
    if (~ret)return ret;

    int a = 1e9, b = 1e9;
    if (p != s[i] - '0') 
        a = solve(i + 1, s[i]-'0');
    int f = 3;
    for (int ii = 0; ii < 3; ii++) {
        if (!i || p==ii)continue;
        int t = solve(i + 1, ii) + 1;
        if (t < b) {
            b = t;
            f = ii;
        }
    }
    if (a < b) {
        nxt[i][p] = { i + 1, s[i] - '0' };
    }
    else {
        nxt[i][p] = { i + 1, f };
    }
    return ret = min(a, b);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (auto& c : s) {
        if (c == 'R')c = '0';
        else if (c == 'G')c = '1';
        else c = '2';
    }
    memset(dp, -1, sizeof(dp));
    cout << solve() << endl;
    pair<int, int> cur = { 0, 3 };
    while (cur.first < n) {
        int c = nxt[cur.first][cur.second].second;
        char cc;
        if (c == 0)cc = 'R';
        else if (c == 1)cc = 'G';
        else cc = 'B';
        cout << cc;
        cur = nxt[cur.first][cur.second];
    }

    return 0;
}