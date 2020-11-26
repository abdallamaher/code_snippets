#include <bits/stdc++.h>
using namespace std;
#define ll long long 

inline void solve() {
    string s;cin >> s;
    map<char, int> mp;
    for (auto it : s)mp[it]++;
    int y = min(mp['D'], mp['U']), x = min(mp['L'], mp['R']);
    if (!x && y)y = 1;
    if (!y && x)x = 1;
    cout << 2 * (y + x) << endl;
    for (int i = 0; i < y; i++)cout << 'U';
    for (int i = 0; i < x; i++)cout << 'L';
    for (int i = 0; i < y; i++)cout << 'D';
    for (int i = 0; i < x; i++)cout << 'R';
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
    return 0;
}