#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        map<int, int> mp;
        int mn = 1e9;
        for (int i = 1; i <= n; i++) {
            if (mp[v[i]]) {
                mn = min(mn, i - mp[v[i]] + 1);
            }
            mp[v[i]] = i;
        }
        if (mn == 1e9)mn = -1;
        cout << mn << '\n';
    }
    return 0;
}