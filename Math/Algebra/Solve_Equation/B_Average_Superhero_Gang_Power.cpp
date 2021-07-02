#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int mxN = 1e5 + 5;

ll n, m, k;
ll ar[mxN];
ll sum;

int main() {
    scanf("%lld%lld%lld", &n, &k, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", ar + i);
        sum += ar[i];
    }
    sort(ar, ar + n);

    ld ans = (ld)(sum + min(k * n, m)) / n;
    for (int i = 1; i < n; i++) {
        if (i > m)break;
        sum -= ar[i - 1];
        ld tmp = (ld)(sum + min(k * (n - i), m - i)) / (n - i);
        ans = max(ans, tmp);
    }

    cout << fixed << setprecision(10) << ans;
}