#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;

inline void solve() {
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    int mx = 0;
    for (int s = 1; s <= 2 * n; s++) {
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            int x = i, y = s - i;
            int cnt1 = mp[x];
            int cnt2 = mp[s - x];

            if (y < x ||  y > n)continue;
            if (x * 2 == s)tmp += cnt1 / 2;
            else tmp += min(cnt2, cnt1);
        }
        mx = max(mx, tmp);
    }
    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}