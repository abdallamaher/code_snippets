#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    int ar[10] = {};
    for (int i = 0; i < 7;i++) {
        scanf("%d", ar + i);
    }
    int sum = accumulate(ar, ar + 7, 0);

    int m = n / sum;
    n %= sum;
    if (n == 0) {
        m--;
        n = sum;
    }

    int ans = 1e9;
    for (int i = 0; i < 7; i++) {
        int tmp = 0, cnt = 0, j = i;
        while (tmp < n) {
            cnt++;
            tmp += ar[j];
            j = (j + 1) % 7;
        }
        ans = min(cnt, ans);
    }
    cout << ans + m * 7 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}