#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    string s; cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == s[i + 1]) {
            s[i + 1] = '#';
            ans++;
        }
        else if (i && s[i + 1] == s[i - 1]) {
            s[i + 1] = '#';
            ans++;
        }
    }
    //cout << s << endl;
    cout << ans << endl;
    //cout << "******\n";
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}