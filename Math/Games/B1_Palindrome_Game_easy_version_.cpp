#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; string s; cin >> n >> s;
    int z = count(s.begin(), s.end(), '0');
    if (z % 2 == 0 || z == 1)cout << "BOB";
    else cout << "ALICE";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}