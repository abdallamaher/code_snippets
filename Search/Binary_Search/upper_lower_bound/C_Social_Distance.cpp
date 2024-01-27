#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')pos.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            i += k;
            continue;
        }
        auto nxt = lower_bound(pos.begin(), pos.end(), i);
        if (nxt != pos.end() && (*nxt) - i <= k)continue;
        ans++;
        i += k;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}