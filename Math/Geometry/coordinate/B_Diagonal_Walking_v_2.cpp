#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll n, m, k; cin >> n >> m >> k;
    if (n > m)swap(n, m);

    if (k < m) {
        cout << -1 << endl;
        return;
    }


    if ((m - n) & 1)k--; // dis is odd   k--
    else if ((k - m) & 1)k -= 2; // dis is even   and    rem moves is odd   k-=2

    cout << k << endl;

}

int main() {
    int t; cin >> t;
    while (t--)solve();
}