#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll sum[1 << 20];
ll f, cnt, ans;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    if (sum[n]%3) {
        return cout << 0, 0;
    }
    f = sum[n] / 3;

    cnt = 0, ans = 0;
    for (int i = 1; i < n; i++) {
        if (sum[i] == f * 2)ans += cnt;
        if (sum[i] == f)cnt++;
    }

    cout << ans << '\n';
    return 0;
}
 