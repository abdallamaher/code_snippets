#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll __gcd(ll a, ll b) {
    return b ? __gcd(b, a % b) : a;
}

inline void solve() {
    ll a, b, k;
    cin >> a >> b >> k;

    if (a > b)swap(a, b);   // b for big
    ll g = __gcd(a, b);     // no number from ]g: b[ is divisible by b
                            // start from g is the wrest case   eg: 4, 8 best check is from 4


    puts(g + (k - 1) * a >= b ? "OBEY" : "REBEL");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}