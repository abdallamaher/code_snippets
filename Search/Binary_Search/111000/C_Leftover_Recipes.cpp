#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../Algorithms/competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define ll long long

int n;
const int N = 15;
ll a[N];
ll b[N];
ll c[N];

int can(int total) {
    int ans = 0;
    for(int i=0; i<=total; i++) {
        int x = i , y = total - i;
        int good = 1;
        for(int j=0; j<n; j++) {
            if(x * b[j] + y * c[j] <= a[j]) {
                continue;
            }
            good = 0;
            break;
        }
        // debug(x, y, good);
        if(good) return 1;
    }
    return 0;
}

inline void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }
    for(int i=0; i<n; i++) {
        cin >> c[i];
    }
    int st = 0, en = 1e9;
    while(st < en) {
        int mid = (st + en + 1) / 2;
        // debug(mid, can(mid));
        if(can(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}
