#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int OO = (int)1e9;
int n, k, ans;
int ar[N];
ll sum[N];
bool can(int x) {
    for (int i = x; i <= n; i++) {
        ll t = 1ll * ar[i-1] * x;
        ll t2 = sum[i] - sum[i - x] + k;
        if (t > t2) continue;
        ans = ar[i-1];
        return 1;
    }
    return 0;
}
int main() {
    cin.sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar, ar + n);
    for (int i = 1; i <= n; i++) {
        sum[i] = ar[i-1] + sum[i-1];
    }
    int st = 0, en = N, mid;
    while (st < en) {
        mid = (st + en + 1) >> 1;
        if (can(mid))
            st = mid;
        else
            en = mid - 1;
    }
    printf("%d %d\n", st, ans);
    return 0;
}





