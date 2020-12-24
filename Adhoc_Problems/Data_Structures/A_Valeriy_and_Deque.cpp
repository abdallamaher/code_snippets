#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, q; cin >> n >> q;
    deque<int> dq;
    int mx = 0;
    for (int i = 0; i < n;i++) {
        int x; scanf("%d", &x);
        mx = max(mx, x);
        dq.push_back(x);
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i < n; i++) {
        int a = dq.front();
        dq.pop_front();
        int b = dq.front();
        dq.pop_front();
        ans.push_back({ a, b });
        if (a < b)swap(a, b);
        dq.push_front(a);
        dq.push_back(b);
    }
    n--;
    dq.pop_front();
    while (q--) {
        ll x; scanf("%lld", &x);
        if (x <= n) {
            cout << ans[x - 1].first << ' ' << ans[x - 1].second << endl;
        }
        else {
            cout << mx << ' ' << dq[--x % n] << endl;
        }
    }
}