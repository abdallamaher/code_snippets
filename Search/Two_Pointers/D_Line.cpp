#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace  std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    string s; cin >> s;
    ll sum = 0;
    for (int i = 0, j = n - 1;i <= j; ++i, --j) {
        if (i == j) {
            sum += i;
            continue;
        }
        if (s[i] == 'L') {
            sum += i;
        }
        else if (s[i] == 'R') {
            sum += n - i - 1;
        }
        if (s[j] == 'L') {
            sum += j;
        }
        else if (s[j] == 'R') {
            sum += n - j - 1;
        }
        // debug(i, j, sum);
    }
    // debug(sum);
    vector<pair<ll, ll> > ch; // add remove
    for (int i = 0, j = n - 1;i < j; ++i, --j) {
        if (s[i] == 'L') {
            ch.push_back({ n - i - 1, i });
        }
        if (s[j] == 'R') {
            ch.push_back({ j, n - j - 1 });
        }
    }
    while (ch.size() < n) {
        ch.push_back({ 0, 0 });
    }
    sort(ch.rbegin(), ch.rend());
    for (int i = 0; i < n; i++) {
        if (i) {
            ch[i].first += ch[i - 1].first;
            ch[i].second += ch[i - 1].second;
        }
        cout << sum + ch[i].first - ch[i].second << ' ';
    }
    cout << endl;
    // debug(ch);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}