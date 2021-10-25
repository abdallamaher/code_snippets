#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n;cin >> n;
    map<int, int> mp;
    for (int i = 0;i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    int ans = 0;
    for (auto& [key, val] : mp) {
        ans += val * (val - 1) / 2;
        for (int i = 1; i < val; i++)mp[key + i]++;
    }
    cout << ans << endl;
}

int main() {
    int n; scanf("%d", &n);
    vector<int> v(n);
    for (auto& it : v)scanf("%d", &it);
    sort(v.begin(), v.end());
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] <= v[i - 1]) {
            sum += v[i - 1] + 1 - v[i];
            v[i] = v[i - 1] + 1;
        }
    }
    cout << sum << '\n';
    return 0;
}