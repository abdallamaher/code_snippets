#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    if (n < 3)return cout << -1, 0;
    else if (n == 3)return cout << 210, 0;
    int r = 1;
    for (int i = 0; i < n - 1; i++) {
        r *= 10;
        r %= 210;
    }
    int c = 210 - r;    // 1000 - (1000%210) + 210  is divisable by 210
    string ans = "";
    while (c) {
        ans += char(c % 10 + '0');
        c /= 10;
    }
    n -= ans.size();
    for (int i = 0; i < n - 1; i++) ans += '0';
    ans += '1';
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}