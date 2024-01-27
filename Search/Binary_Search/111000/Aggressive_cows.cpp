#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
int ar[N];
int n, k;

bool ok(int dis) {
    int cnt = 1;
    for (int i = 1, pre = 0; i < n; i++) {
        if (ar[i] - ar[pre] >= dis) {
            pre = i;
            cnt++;
        }
    }
    return cnt >= k;
}

inline void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)cin >> ar[i];
    sort(ar, ar + n);
    int st = 1, en = 1e9 + 5, mid;
    while (st < en) {
        mid = (st + en + 1) / 2;
        if (ok(mid))st = mid;
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