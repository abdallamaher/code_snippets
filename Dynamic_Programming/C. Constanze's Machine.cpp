#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5, mod = 1e9 + 7;
ll dp[N];
string s;

ll solve(int i=0) {
    if (i == s.length())return 1;
    ll& ret = dp[i];
    if (~ret)return ret;

    ret = solve(i + 1);
    if (i < s.length() && s[i] == s[i + 1] && (s[i] == 'n' || s[i] == 'u'))
        ret += solve(i + 2);
    if (ret > mod)ret %= mod;
    return ret;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    int f = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'm' || s[i] == 'w')
            f = 1;
    }
    if (f)return cout << 0, 0;
    memset(dp, -1, sizeof(dp));
    cout << solve();
    return 0;
}
