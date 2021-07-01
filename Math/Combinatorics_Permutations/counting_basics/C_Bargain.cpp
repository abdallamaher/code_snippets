#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;


int main() {
    string s; cin >> s;
    int n = s.size();
    ll sum = 0;
    vector<ll> power({ 1 });
    for (ll i = 1; i < n; i++) {
        power.push_back((power.back() * 10) % mod);
    }
    reverse(power.begin(), power.end());


    // left
    for (ll i = 0;i < n;i++) {
        ll cnt = (i * (i + 1) / 2);
        cnt %= mod;
        sum += cnt * power[i] * (s[i] - '0');
        sum %= mod;
    }


    // right
    vector<ll> right({ 0 });
    for (ll i = 1; i <= n; i++) {
        ll x = right.back() + i * power[n - i];
        right.push_back(x % mod);
    }
    reverse(right.begin(), right.end());
    for (ll i = 0;i < n - 1;i++) {
        sum += (s[i] - '0') * right[i + 1];
        sum %= mod;
    }



    cout << sum << endl;


}