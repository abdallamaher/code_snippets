#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; string s; cin >> n >> s;
    // cost to make all connected to * idx

    vector<pair<int, int>> ar;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.')continue;
        int j = i;
        while (s[j] == '*')j++;
        ar.push_back({ i, j - 1 });
        i = j - 1;
    }
    n = ar.size();
    ll pre[n] = {};
    pre[0] = 0;
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        pair<int, int> p = ar[i - 1];
        pair<int, int> cur = ar[i];
        sum += p.second - p.first + 1;

        int len = cur.first - p.second - 1;
        pre[i] = pre[i - 1] + len * sum;
    }
    ll suf[n] = {};
    sum = 0;
    for (int i = n - 2; i >= 0; i--) {
        pair<int, int> p = ar[i + 1];
        pair<int, int> cur = ar[i];
        sum += p.second - p.first + 1;

        int len = p.first - cur.second - 1;
        suf[i] = suf[i + 1] + len * sum;
    }
    ll ans = 1e12;
    for (int i = 0; i < n; i++) {
        ans = min(ans, pre[i] + suf[i]);
    }
    if (n == 0)ans = 0;
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}