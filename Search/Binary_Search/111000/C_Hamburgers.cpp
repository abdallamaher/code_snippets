#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ing[4];
ll have[4];
ll oneCost[4];
ll r;

bool ok(ll num) {
    ll need[4] = {};
    ll sum = 0;
    for (int i = 1; i <= 3; i++) {
        need[i] = num * ing[i] - have[i];
        if (need[i] > 0)need[i] *= oneCost[i];
        else need[i] = 0;
        sum += need[i];
    }
    return r >= sum;
}

inline void solve() {
    string s; cin >> s;
    for (auto& it : s) {
        if (it == 'B')ing[1]++;
        else if (it == 'S')ing[2]++;
        else ing[3]++;
    }
    for (int i = 1; i <= 3;i++) cin >> have[i];
    for (int i = 1; i <= 3;i++)cin >> oneCost[i];
    cin >> r;

    ll st = 0, en = 1e13, mid;
    while (st < en) {
        mid = (st + en + 1) / 2;
        if (ok(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}