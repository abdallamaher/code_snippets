#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline bool prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)return 0;
    }
    return 1;
}

inline void solve() {
    string win = "Ashishgup", lose = "FastestFinger";
    int n; cin >> n;

    if (n == 1) cout << lose;
    else if (n & 1)cout << win;
    else if (n == 2)cout << win;
    else if (__builtin_popcount(n) == 1)cout << lose;
    else if (prime(n / 2))cout << lose;
    else cout << win;   // 2 * odd * odd * odd * ..... * odd  === 2 * odd * odd

    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}