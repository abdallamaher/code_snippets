#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
string s;
map<int, int> dp;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;

    int cnt = 0, ans = 0;
    // dp[balace] = index
    dp[0] = -1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '1') cnt++;
        else cnt--;

        // loop at prefixes in o(n) get timeLimit, and as we need first apperance use map
        if (dp.find(cnt) == dp.end())
            dp[cnt] = i;
        else
            ans = max(ans, i - dp[cnt]);
    }
    cout << ans;
    return 0;
}
