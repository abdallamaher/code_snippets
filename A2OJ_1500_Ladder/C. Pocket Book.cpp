#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n, m;
set<char> se[110];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; s[j]; j++)
            se[j].insert(s[j]);
    }
    ll ans = 1;
    for (int i = 0; i < m; i++) {
        ans *= se[i].size();
        if (ans > mod) ans %= mod;
    }
    cout << ans;
    return 0;
}