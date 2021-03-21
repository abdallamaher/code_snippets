#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, c;
const int N = 2e5 + 5;
int ar[N];

inline bool can(int dis) {
    int pre = 0, cnt = 1;
    for (int i = 1; i < n;i++) {
        if (ar[i] - ar[pre] >= dis)pre = i, cnt++;
    }
    return cnt >= c;
}

inline void solve() {
    scanf("%d %d", &n, &c);
    for (int i = 0;i < n;i++)scanf("%d", ar + i);
    sort(ar, ar + n);
    int st = 1, en = 1e9 + 5, mid;
    while (st < en) {
        mid = (st + en + 1) / 2;
        if (can(mid)) st = mid;
        else en = mid - 1;
    }
    printf("%d\n", en);
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}