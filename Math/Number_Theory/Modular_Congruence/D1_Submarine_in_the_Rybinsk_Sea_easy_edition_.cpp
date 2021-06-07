#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int mod = 998244353;



int main() {
    ll n; cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll num; cin >> num;
        ll sum = 0, po = 1;
        while (num) {
            int dig = num % 10;

            sum = (sum + po * dig) % mod;
            po *= 10;

            sum = (sum + po * dig) % mod;
            po *= 10;


            num /= 10;
        }
        ans += (sum * n) % mod;
        ans %= mod;
    }

    cout << ans << endl;
}