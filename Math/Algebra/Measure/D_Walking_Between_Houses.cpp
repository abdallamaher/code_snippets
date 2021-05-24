#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, s;

bool can(ll a) {
    return a >= 1 && a <= n;
}

int main() {
    cin >> n >> k >> s;
    ll mn = k;
    ll mx = k * (n - 1);

    if (s< mn || s > mx) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    ll pos = 1;
    while (k--) {
        ll ad = min(s - k, n - 1);
        if (can(pos + ad))pos = pos + ad;
        else pos = pos - ad;
        s -= ad;
        cout << pos << ' ';
    }
}