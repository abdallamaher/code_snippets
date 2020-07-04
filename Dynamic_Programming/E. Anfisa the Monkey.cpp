#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int k, a, b, n;
string s;
int dp[210][210];
void print(int len, int k) {
    if (len<1)return;
    int cut = dp[len][k];
    print(len - cut, k - 1);
    for (int i = len - cut; i < len; i++) {
        cout << s[i];
    }
    cout << '\n';
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k >> a >> b >> s;

    n = s.length();
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i][j] == 0)continue;
            for (int cut = a; cut <= b && i + cut <= n; cut++) {
                dp[i + cut][j + 1] = cut;
            }
        }
    }

    if (dp[n][k])print(n, k);
    else cout << "No solution\n";
    return 0;
}


