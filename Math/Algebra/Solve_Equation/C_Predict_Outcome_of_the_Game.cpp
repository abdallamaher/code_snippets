#include<bits/stdc++.h>
using namespace std;
#define ll long long


void inline solve() {
    ll n, k, d1, d2;
    scanf("%lld%lld%lld%lld", &n, &k, &d1, &d2);
    bool flag = false;
    for (int i = -1; i < 2; i += 2) {
        for (int j = -1; j < 2; j += 2) {
            ll x3 = k - j * 2 * d2 - i * d1;
            if (x3 % 3 == 0) {
                ll ar[3] = {
                    x3 / 3,
                    x3 / 3 + j * d2,
                    x3 / 3 + j * d2 + i * d1
                };
                sort(ar, ar + 3);
                ll minCostToEuql = ar[2] - ar[0] + ar[2] - ar[1];
                if (ar[0] < 0)continue;
                if (k + minCostToEuql > n)continue;
                if ((n - k - minCostToEuql) % 3 == 0)flag = true;
            }
        }
    }
    puts(flag ? "yes" : "no");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}



/*
 x1 + x2 + x3 = k
|x1 - x2| = d1
|x2 - x3| = d2

if  x1 >= x2
then
x1 - x2 = d1
so
x1 = d1 + x2

if  x2 >= x3
then
x2 - x3 = d2
so
x2 = d2 +x3

x3 = k - x2 - x1
x3 = k - x2 - (d1 + x2)
x3 = k - (d2 + x3) - d1 - (d2 + x3)
3x3 = k - 2d2 - d1
*/