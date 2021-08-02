#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a, b, aa, bb;
ll divA, divB, divC;

ll lcm(ll x, ll y) {
    return x / __gcd(x, y) * y;
}

int main() {
    cin >> n >> a >> b >> aa >> bb;

    divA = n / a;
    divB = n / b;
    divC = n / lcm(a, b);

    divA -= divC;
    divB -= divC;

    ll ans = divA * aa + divB * bb + divC * max(aa, bb);
    cout << ans << endl;
}