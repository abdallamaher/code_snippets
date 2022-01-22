#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int q, d; cin >> q >> d;
    while (q--) {
        int x; cin >> x;
        int ok = 0;
        // x = 81 and d = 7         81-7=74 
        if (x >= d * 10)ok = 1;
        else {
            // d + d + d        10+d
            for (int i = 1; i <= 9; i++) {
                if (x - d * i >= 0 && (x - d * i) % 10 == 0)ok = 1;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}