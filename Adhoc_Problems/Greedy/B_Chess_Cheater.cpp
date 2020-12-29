#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for (auto& it : s)
        if (it == 'W')it = 1;
        else it = 0;
    vector < pair<int, pair<int, int> > > gaps;
    for (int i = 0, cnt = 0; i < n; i++) {
        if (s[i] == 1)continue;
        int j = i + 1;
        while (s[i] == s[j])j++;
        if (i && j < n)gaps.push_back({ j - i, {i, j - 1} });
        i = j;
    }
    sort(gaps.begin(), gaps.end());
    for (int i = 0; i < gaps.size(); i++) {
        if (k < gaps[i].first)break;
        for (int j = gaps[i].second.first; j <= gaps[i].second.second;j++)
            s[j] = 1, k--;
    }
    for (int i = 0; i < n; i++) {
        while (k && i && s[i] == 1 && s[i - 1] == 0) {
            k--;
            s[i - 1] = 1;
            i--;
        }
        while (k && i < n - 1 && s[i] == 1 && s[i + 1] == 0) {
            k--;
            s[i + 1] = 1;
            i++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (k && s[i] == 0) {
            k--;
            s[i] = 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n;i++) {
        if (i && s[i] == 1 && s[i - 1] == 1)ans += 2;
        else if (s[i] == 1)ans++;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}