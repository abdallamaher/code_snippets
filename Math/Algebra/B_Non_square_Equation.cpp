#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

inline int sum(ll x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}


inline int solve_quadratic_equation() {
    ll c; cin >> c;
    c *= -1;
    for (int b = 1, a = 1; b <= 9 * 10; b++) {
        ll sq = b * b - 4 * a * c;
        if (sq < 0 || (ll)sqrt(sq) * (ll)sqrt(sq) != sq) continue;  // integar
        sq = sqrt(sq);
        ll x = (-b + sq) / 2;
        if (x >= 0 && sum(x) == b)return cout << x, 0;      // positive && more than one answer so diff sum
        x = (-b - sq) / 2;
        if (x >= 0 && sum(x) == b)return cout << x, 0;
    }
    cout << -1;
}

int main() {
    ll c; cin >> c;
    ll s = sqrt(c);
    for (ll x = max(1ll, s - 100); x <= s; x++) {   
        if (x * x + x * sum(x) == c)return cout << x, 0;
    }
    cout << -1;
}