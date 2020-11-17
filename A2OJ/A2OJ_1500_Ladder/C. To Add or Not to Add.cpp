#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, d, mn;
int ar[N];
ll sum[N];

bool check(int x) {
    x--;
    for (int i = 1; i + x <= n; i++) {
        if (1ll * ar[i + x] * (x + 1) - (sum[i + x] - sum[i - 1]) <= d) {
            mn = ar[i + x];
            return 1;
        }
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    sort(ar + 1, ar + n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + ar[i];
    }


    int st = 0, en = 1e9, mid;
    while (st < en) {
        mid = (st + en + 1) >> 1;
        if (check(mid))
            st = mid;
        else
            en = mid - 1;
    }
    cout << st << ' ' << mn;
    return 0;
}
