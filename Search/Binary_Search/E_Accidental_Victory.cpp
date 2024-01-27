#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
pair<ll, int> ar[N] = {};
ll sum[N];
int n;
inline bool can(int x) {
    for (int i = x + 1; i <= n; i++) {
        if (sum[i - 1] < ar[i].first) {
            return 0;
        }
    }
    return 1;
}

inline void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &ar[i].first);
        ar[i].second = i;
    }
    sort(ar + 1, ar + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + ar[i].first;
    int st = 1, en = n, mid;
    while (st < en) {
        mid = (st + en) / 2;
        if (can(mid))en = mid;
        else st = mid + 1;
    }
    vector<int> ans;
    for (int i = st; i <= n; i++)
        ans.push_back(ar[i].second);
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for (auto it : ans)printf("%d ", it);
    puts("");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}