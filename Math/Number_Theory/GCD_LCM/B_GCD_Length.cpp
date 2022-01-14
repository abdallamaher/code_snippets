#include <bits/stdc++.h>
using namespace std;
#define ll long long

int check(ll n) {
    int res = 0;
    while (n) {
        res++;
        n /= 10;
    }
    return res;
}

inline void solve() {
    int a, b, c; cin >> a >> b >> c;
    ll num1 = 0, num2 = 0;
    while (c) {
        c--;
        num1 = num1 * 10 + 1;
        num2 = num2 * 10 + 1;
    }
    while (check(num1) < a) {
        num1 *= 2;
    }
    while (check(num2) < b) {
        num2 *= 3;
    }
    cout << num1 << ' ' << num2 << endl;
    // cerr << __gcd(num1 , num2) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}