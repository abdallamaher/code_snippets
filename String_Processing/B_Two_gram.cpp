#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n;string str; cin >> n >> str;
    map<string, int> mp;
    int mx = 0;
    string ans;
    for (int i = 1; i < n; i++) {
        string tmp = string(1, str[i - 1]) + str[i];
        mp[tmp]++;
        if (mp[tmp] > mx) {
            mx = mp[tmp];
            ans = tmp;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}