#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, d, e; cin >> n >> d >> e;
    e *= 5;
    int mn = 1e9;
    for (int i = 0; i <= n; i++) {
        int take = i * e;
        int rem = n - take;
        if (take > n)break;
        rem %= d;
        mn = min(mn, rem);
    }
    cout << mn;
}