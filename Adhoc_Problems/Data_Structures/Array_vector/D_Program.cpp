#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, q; string s; scanf("%d %d", &n, &q);
    cin >> s;
    s = "$" + s;

    vector<int> sum(n + 5);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1];
        if (s[i] == '+')sum[i]++;
        else sum[i]--;
    }

    vector<pair<int, int>> left(n + 5), right(n + 5);
    for (int i = 1; i <= n; i++) {
        left[i].first = min(left[i - 1].first, sum[i]);
        left[i].second = max(left[i - 1].second, sum[i]);
    }

    right[n + 1].first = 1e9;
    right[n + 1].second = -1e9;
    for (int i = n; i >= 1;i--) {
        right[i].first = min(right[i + 1].first, sum[i]);
        right[i].second = max(right[i + 1].second, sum[i]);
    }

    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        int mn = min(left[l - 1].first,
            sum[l - 1] + (right[r + 1].first - sum[r])
        );
        int mx = max(left[l - 1].second,
            sum[l - 1] + (right[r + 1].second - sum[r])
        );
        printf("%d\n", mx - mn + 1);
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}