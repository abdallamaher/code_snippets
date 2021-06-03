#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll a, b; cin >> a >> b;
    // make a not divisible by b
    // relation of divisibility and primeFactories

    if (a % b != 0) {
        cout << a << endl;
        return;
    }


    set<ll> primeFac;
    ll bb = b;
    for (ll i = 2 ;i * i <= bb; i++) {
        while (bb % i == 0) {
            primeFac.insert(i);
            bb /= i;
        }
    }
    if (bb > 1)primeFac.insert(bb);


    ll best = 0;
    for (auto it : primeFac) {
        ll aa = a;
        while (aa % b == 0)aa /= it;
        best = max(best, aa);
    }
    cout << best << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}