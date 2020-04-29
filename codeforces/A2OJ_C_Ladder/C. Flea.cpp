#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, s;
map<ll, ll> m1, m2;
// 4 3 2

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        int s1 = (i-1) / s + (n - i) / s + 1;
        if (s1 > mx)mx = s1;
        m1[s1]++;
        //printf("%d %d\n", i, s1);
    }
    ll mx2 = 0;
    for (int i = 1; i <= m; i++) {
        int s1 = (i - 1) / s + (m - i) / s + 1;
        if (s1 > mx2)mx2 = s1;
        m2[s1]++;
        //printf("%d %d\n", i, s1);
    }
    cout << m1[mx] * m2[mx2];
    return 0;
}