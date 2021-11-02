#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int  n; cin >> n;
    vector<int> v(n);
    for (auto& it : v)cin >> it;
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0, j = 0;i < n; i++) {
        while (j < n && v[j] - v[i] <= 5) {
            j++;
            ans = max(ans, j - i);
        }
    }
    cout << ans << endl;
}

void go() {
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    int ans = 0;
    for (auto& [key, val] : mp) {
        int tmp = 0;
        for (int i = 0; i <= 5; i++) {
            if (mp.count(key + i))tmp += mp[key + i];
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)go();
}