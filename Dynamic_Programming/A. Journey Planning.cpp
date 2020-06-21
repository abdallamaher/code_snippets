#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<int, int> mp;
ll ans;
int n;
const int N = 2e5 + 5;
int ar[N];
ll dp[N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];

    }
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[mp[ar[i] - i]] + ar[i]);
        mp[ar[i] - i] = i;
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}

