#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}


int main() {
    int n, m; scanf("%d %d", &n, &m);
    ll A[n] = {};
    for (int i = 0; i < n; i++)  scanf("%lld", A + i);

    // gcd(a1, a2, a3) == gcd(a1, |a1-a2|, |a1-a3|);
    ll g = 0;
    for (int i = 1; i < n; i++)  g = gcd(g, abs(A[0] - A[i]));

    for (int i = 0; i < m; i++) {
        ll b; scanf("%lld", &b);
        printf("%lld ", gcd(A[0] + b, g));
    }

}