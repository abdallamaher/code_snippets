#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
ll ing[N];
ll oneCost[N];
ll have[N];
ll n, k;

bool ok(ll num) {
    ll t = k;
    for (int i = 0; i < n; i++) {
        ll oneNeed = oneCost[i] * num - have[i];
        t -= max(0ll, oneNeed);
        if (t < 0)return 0;
    }
    return t >= 0;
}

inline void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)cin >> oneCost[i];
    for (int i = 0; i < n; i++)cin >> have[i];
    ll st = 0, en = 2e9 + 5, mid;
    while (st < en) {
        mid = (st + en + 1) / 2;
        if (ok(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}