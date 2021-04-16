#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
void solve() {
    int n; scanf("%d", &n);
    int a = 1, b = n-1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            a = n/i; // greatest gcd, so take big part
            b = n - a;
            break; // as we take big part first, so first is the bigest
        }
    }
    printf("%d %d\n", a, b);
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}