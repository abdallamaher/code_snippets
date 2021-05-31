#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;

int ar[N];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)scanf("%d", ar + i);

    sort(ar, ar + n);

    ll ans = LLONG_MAX;
    for (int c = 1; c < N; c++) {
        ll sum = 0, p = 1;
        bool ok = 1;
        for (int j = 0; j < n; j++) {
            sum += abs(ar[j] - p);
            if (j < n - 1 && p > LLONG_MAX / p) {
                ok = 0;
                break;
            }
            p *= c;
        }
        if (ok)ans = min(ans, sum);
    }
    cout << ans << endl;
}