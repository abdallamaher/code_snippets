#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, T; cin >> n >> T;
    vector<ll> ar(n);
    for (auto& it : ar)scanf("%d", &it);

    ll ans = 0;
    while (true) {
        ll cnt = 0, p = 0;
        for (auto& it : ar) {
            if (T >= it) {
                cnt++;
                p += it;
                T -= it;
            }
        }

        if (cnt == 0)break;

        ans += cnt;
        ans += cnt * (T / p);
        T %= p;
    }

    cout << ans << endl;
}