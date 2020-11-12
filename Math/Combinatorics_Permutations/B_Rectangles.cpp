#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll ncr(int n, int r) {
    ll up = 1, down = 1;
    r = min(r, n - r);
    while (r) {
        up *= n;
        down *= r;

        long long g = __gcd(up, down);
        up /= g;
        down /= g;

        n--;
        r--;
    }
    return up;
}

int main() {
    int r[55][3] = {}, c[55][3] = {};
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0;j < m; j++) {
            int x; scanf("%d", &x);
            r[i][x]++;
            c[j][x]++;
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int a = r[i][0];
        int b = r[i][1];
        sum += (1ll << a) - 1;
        sum += (1ll << b) - 1;
        //for (int j = 2;j <= a; j++)sum += ncr(a, j);
        //for (int j = 2;j <= b; j++)sum += ncr(b, j);
    }
    for (int i = 0; i < m; i++) {
        int a = c[i][0];
        int b = c[i][1];
        sum += (1ll << a) - 1;
        sum += (1ll << b) - 1;
        //for (int j = 2;j <= a; j++)sum += ncr(a, j);
        //for (int j = 2;j <= b; j++)sum += ncr(b, j);
    }
    //cout << sum + (n * m) << endl;
    cout << sum - (n * m) << endl;
    return 0;
}