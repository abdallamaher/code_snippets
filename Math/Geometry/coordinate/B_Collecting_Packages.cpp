#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v;
    v.push_back({ 0, 0 });
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back({ x, y });
    }
    sort(v.begin(), v.end());
    string s;
    for (int i = 1; i < v.size();i++) {
        int x = v[i].first - v[i - 1].first;
        int y = v[i].second - v[i - 1].second;
        if (x < 0 || y < 0) {
            cout << "NO" << endl;
            return;
        }
        while (x--)s += 'R';
        while (y--)s += 'U';
    }
    cout << "YES\n" << s << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}