#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
string s;
map<int, int> mp;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;

    int cnt = 0, ans = 0;
    // mp[balace] = index
    mp[0] = -1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '1') cnt++;
        else cnt--;

        // loop at prefixes in o(n) get timeLimit, and as we need first apperance use map
        if (mp.find(cnt) == mp.end())
            mp[cnt] = i;
        else
            ans = max(ans, i - mp[cnt]);
    }
    cout << ans;
    return 0;
}
