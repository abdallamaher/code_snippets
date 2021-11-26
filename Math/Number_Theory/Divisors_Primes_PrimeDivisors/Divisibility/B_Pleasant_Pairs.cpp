#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    map<int, int> mp;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        int b = 1;
        while (a * b <= 2 * n) {
            if (mp[b] && b * a == mp[b] + i)ans++;
            b++;
        }
        mp[a] = i;
    }
    cout << ans << endl;
}

void go() {
    int n; cin >> n;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        v.push_back({ x, i });
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (1ll * v[i].first * v[j].first > 2 * n)break;
            if (v[i].first * v[j].first == v[i].second + v[j].second)ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)go();
}