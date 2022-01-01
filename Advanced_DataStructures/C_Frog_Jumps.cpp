#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long 

inline void solve() {
    string s; cin >> s;
    s = '#' + s + 'R';
    int mx = 0;
    for (int i = 1, p = 0; i < s.size(); i++) {
        if (s[i] == 'R') mx = max(i - p, mx), p = i;
    }
    cout << mx << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}