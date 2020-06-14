#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n, t;
vector<int> capList[110];
int dp[101][1<<11];

int solve(int i = 1, int msk = 0) {

    if (msk == (1 << n) - 1) return 1;
    if (i > 100)return 0;

    int& ret = dp[i][msk];
    if (~ret)return ret;

    ret = solve(i + 1, msk);
    for (auto& it : capList[i]) {
        if (msk & (1 << it)) continue;
        ret += solve(i + 1, msk | (1 << it));
        if (ret > mod)ret -= mod;
    }
    return ret;
}

void init() {
    memset(dp, -1, sizeof(dp));
    for (auto& it : capList) {
        it.clear();
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        init();
        cin >> n; cin.ignore();
        for (int i = 0; i < n; i++) {
            string s; getline(cin, s);
            stringstream stream(s);
            int x;
            while (stream >> x)
                capList[x].push_back(i);
        }
        cout << solve() << endl;
    }
    return 0;
}