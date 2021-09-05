#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> ar(n);
    map<int, int> mp;
    for (auto& it : ar) cin >> it, mp[it]++;
    int diff = -1;
    for (auto& [key, val] : mp) {
        if (val != 1)diff = key;
    }
    for (int i = 0; i < n;i++) {
        if (ar[i] != diff) {
            cout << i + 1 << endl;
            return;
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}