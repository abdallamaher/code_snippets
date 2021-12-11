#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e4 + 4;
int dp[N];
int n, a, b, c;

int go(int rem) {
    if (rem < 0)return -1e9;
    if (rem == 0)return 0;
    int& ret = dp[rem];
    if (~ret)return ret;
    int A = go(rem - a) + 1;
    int B = go(rem - b) + 1;
    int C = go(rem - c) + 1;
    return ret = max({ A, B, C });
}

inline void solve() {
    cin >> n >> a >> b >> c;
    memset(dp, -1, sizeof(dp));
    cout << go(n) << endl;
}

void run() {
    cin >> n >> a >> b >> c;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int x = n - i * a - j * b;
            if (x < 0 || x / c != (x + c - 1) / c)continue;
            ans = max(ans, i + j + x / c);
        }
    }
    cout << ans << endl;
}


void exc(void) {
    int n, a, b, c, i;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    for (i = 1; i <= n; i++) dp[i] = -1;
    for (i = 0; i <= n; i++) {
        if (dp[i] == -1) continue;
        dp[i + a] = max(dp[i + a], dp[i] + 1);
        dp[i + b] = max(dp[i + b], dp[i] + 1);
        dp[i + c] = max(dp[i + c], dp[i] + 1);
    }
    cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) exc();
}