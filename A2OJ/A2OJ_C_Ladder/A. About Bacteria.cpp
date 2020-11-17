#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
int k, b, n, t;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k >> b >> n >> t;
    ll x = 1;
    while (true) {
        x = k * x + b;
        if (x > t)break;
        --n;
        //cout << x << ' ';
    }
    if (n <= 0)cout << 0;
    else cout << n;
    return 0;
}