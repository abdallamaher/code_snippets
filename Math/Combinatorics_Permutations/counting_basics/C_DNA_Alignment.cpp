#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

ll power(ll n, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)res = (res * n) % mod;
        n = (n * n) % mod;
        p /= 2;
    }
    return res;
}

int main() {
    int n; string s; cin >> n >> s;
    map<char, int> mp;
    for (auto c : s)mp[c]++;
    int mx = 0;
    for (auto it : mp)mx = max(mx, it.second);
    int cnt = 0;
    for (auto it : mp)cnt += bool(mx == it.second);
    cout << power(cnt, n) << endl;
}