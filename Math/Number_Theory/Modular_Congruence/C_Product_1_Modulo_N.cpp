#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n; cin >> n;
    // product of coprimes < n      = 1 mod n
    // coprime pair up as inverses to mod n   which equal 1
    // wilson's theorem special case

    set<int> coPrimes;
    ll prod = 1;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            coPrimes.insert(i);
            prod = (prod * i) % n;
        }
    }
    if (prod != 1) {
        coPrimes.erase(coPrimes.find(prod));
    }

    cout << coPrimes.size() << endl;
    for (auto it : coPrimes)printf("%d ", it);
}