#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c, m, x;

bool can(int mid) {
    int sum = c + m + x - 2 * mid;
    if (c < mid || m < mid || sum < mid)return 0;
    return 1;
}

inline void solve() {
    cin >> c >> m >> x;
    int st = 0, en = 1e9, mid;
    while (st < en) {
        mid = (st + en + 1) / 2;
        if (can(mid))st = mid;
        else en = mid - 1;
    }
    cout << st << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}