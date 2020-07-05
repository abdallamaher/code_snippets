#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, x, y;

bool can(ll t) {
    if (t - t / x < n)return 0;

    if (t - t / y < m)return 0;
    
    int lcm = x * y;    // numbers can divide x or y
    if (t - t / lcm < n + m)return 0;   // numbers can't divide x nor y

    return 1;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> x >> y;
    ll st = 1, en = 1e12, mid;
    while (st < en) {
        mid = st + en >> 1;
        if (can(mid))
            en = mid;
        else
            st = mid + 1;
    }
    cout << en << '\n';
    return 0;
}
