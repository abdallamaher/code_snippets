#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; string s; cin >> n >> s;
    /*
    1111
    20
    300
    23000
    */
    map<int, int> mp;
    ll ans = 0, sum = 0;
    mp[0] = 1;
    for (int i = 0;i < n; i++) {
        int x = (s[i] - '0') - 1;
        sum += x;
        ans += mp[sum];
        mp[sum]++;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}