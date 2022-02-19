#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        int st = 0, en = n - 1, mid;
        while (st < en) {
            mid = (st + en) / 2;
            if (v[mid] >= x)en = mid;
            else st = mid + 1;
        }
        if (v[en] == x) cout << "Yes ";
        else cout << "No ";
        cout << st + 1 << endl;
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}