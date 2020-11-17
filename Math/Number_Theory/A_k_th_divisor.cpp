#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> a, b;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
            if (i != n / i)b.push_back(n / i);
        }
    }


    // cout << (k - a.size()) << endl;
    if (a.size() + b.size() < k)cout << -1;
    else cout << (k > a.size() ? b[b.size() - (k - a.size())] : a[k - 1]);
    return 0;
}