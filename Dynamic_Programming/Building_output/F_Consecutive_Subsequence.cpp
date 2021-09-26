#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    int ar[n] = {};
    map<int, int> dp;
    for (int i = 0;i < n; i++) {
        cin >> ar[i];
    }
    int ans = 0;
    for (int i = 0;i < n; i++) {
        dp[ar[i]] = 1 + dp[ar[i] - 1];
        if (dp[ar[i]] > dp[ans]) {
            ans = ar[i];
        }
    }
    cout << dp[ans] << endl;

    for (int num = ans - dp[ans] + 1, i = 0; i < n && num <= ans; i++) {
        if (num == ar[i]) {
            cout << i + 1 << ' ';
            num++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}