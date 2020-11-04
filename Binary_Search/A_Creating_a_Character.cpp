#include <bits/stdc++.h>
using namespace std;
#define ll long long 

inline void solve() {
    int s, i, e; scanf("%d%d%d", &s, &i, &e);
    int st = 0, en = e, mid;
    while (st <= en) {
        mid = (st + en + 1) >> 1;
        if (i + mid < s + (e - mid))st = mid + 1;
        else en = mid - 1;
    }
    cout << st << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}