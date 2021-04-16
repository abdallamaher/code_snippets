#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

vector<ll> factor;
inline void prime_factorization(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0)factor.push_back(i), n /= i;
    }
    if(n != 1)factor.push_back(n);
}

int main() {
    ll n; cin >> n;
    prime_factorization(n);
    if (factor.size() <= 1)cout << "1\n0";
    else if (factor.size() == 2)cout << "2";
    else cout << "1\n" << factor[0] * factor[1];
}