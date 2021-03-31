#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ar[40] = {};
    for (int i = 0;i < n; i++) {
        char c; cin >> c;
        ar[c - 'a'] = 1;
    }
    ll ans = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        int cnt = 0;
        while (j < n && ar[s[j++] - 'a'])cnt++, ans += cnt;
        // ans += cnt + 1ll * cnt * (cnt - 1) / 2;     //ncr(cnt, 1) + ncr(cnt, 2)
        i = j;
    }
    cout << ans << endl;
}