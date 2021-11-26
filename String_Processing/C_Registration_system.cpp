#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (mp[s] == 0) {
            cout << "OK" << endl;
        }
        else {
            cout << s << mp[s] << endl;
        }
        mp[s]++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}