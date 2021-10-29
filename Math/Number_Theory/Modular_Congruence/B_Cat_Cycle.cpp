#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k;
    cin >> n >> k;
    k--;
    if (n % 2 == 0) {
        cout << (k % n) + 1 << endl;
        return;
    }
    int preConflict = (n - 1) / 2;
    int conflict = k / preConflict;
    k += conflict;
    cout << (k % n + 1) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}