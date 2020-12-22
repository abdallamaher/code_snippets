#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> prime_factors(ll n) {
    vector<ll> f;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            f.push_back(i);
            while (n % i == 0)n /= i;
        }
    }
    if (n > 1)f.push_back(n);
    return f;
}

int main() {
    ll n; cin >> n;
    vector<ll> f = prime_factors(n);
    if (f.size() == 0)cout << n;
    else if (f.size() == 1)cout << f.back();
    else cout << 1;
}