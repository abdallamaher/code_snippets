#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    int ar[n + 1] = {};
    set<pair<int, int>> s;
    s.insert({ n, -1 });
    int cnt = 0;
    while (s.size()) {
        auto cur = *s.rbegin();
        s.erase(cur);
        int st = -cur.second;
        int en = cur.first + st - 1;
        int mid = (st + en) / 2;

        if (mid - st) s.insert({ mid - st, -st });
        if (en - mid)
            s.insert({ en - mid, -(mid + 1) });

        cnt++;
        ar[mid] = cnt;

    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ar[i]);
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}