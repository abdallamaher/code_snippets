#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    string s; cin >> s;
    if (s == "1") {
        cout << "0\n";
        return;
    }
    int n = s.size();
    int f = 0;
    for (int i = 0; i < s.size(); i++) {
        if (f == 0 && (i == n - 1 || s[i] == '0')) {
            f = 1;
            continue;
        }
        cout << s[i];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}