#include <bits/stdc++.h>
using namespace std;
#define ll long long


inline void go() {
    ll n, k; cin >> n >> k;
    ll preSum = 0, add = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        ll st = 0, en = 1e12, mid;
        while (st < en) {
            mid = (st + en) / 2;
            if (100 * x <= (preSum + mid) * k) {
                en = mid;
            }
            else {
                st = mid + 1;
            }
        }
        preSum += x;
        if (i)add = max(add, en);
    }
 
    cout << add << endl;
}


inline void solve() {
    ll n, k; cin >> n >> k;
    ll sum = 0;
    ll add = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        if (i) {
            add = max(add, (100 * x - sum * k + k - 1) / k);
        }
        sum += x;
    }

    cout << add << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}