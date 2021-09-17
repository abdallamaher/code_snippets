#include <bits/stdc++.h>
using namespace std;
#define ll long long

string ans[] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
inline void solve() {
    ll n;cin >> n;
    n--;
    ll x = 5;
    while (n >= x) {
        n -= x;
        x *= 2;
    }
    // now x is greater
    int part_len = x / 5;
    int idx = n / part_len;
    cout << ans[idx] << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}