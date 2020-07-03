#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, d;
int ar[30000];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> d;
    n = n * m;
    int f = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        f |= bool(ar[i]%d != ar[0]%d);
    }
    if (f)return cout << -1 << endl, 0;

    sort(ar, ar + n);
    int mid = (n + 1) >> 1;
    mid--;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > mid)
            ans += (ar[i] - ar[mid]) / d;
        else
            ans += (ar[mid] - ar[i]) / d;
    }
    cout << ans << endl;
    return 0;
}
