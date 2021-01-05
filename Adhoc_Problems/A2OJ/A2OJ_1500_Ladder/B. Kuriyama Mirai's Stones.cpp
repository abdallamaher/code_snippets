#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, m, l, r, t;
ll a[N], b[N];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 2; i <= n; i++) {
        b[i] += b[i - 1];
        a[i] += a[i - 1];
    }
    cin >> m;
    while (m--) {
        cin >> t >> l >> r;
        if (t == 1) {
            cout << a[r] - a[l - 1] << endl;
        }
        else
            cout << b[r] - b[l - 1] << endl;
    }
    return 0;
}
