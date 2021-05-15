#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    if (n <= 3) {
        cout << -1 << endl;
        return;
    }
    if (n & 1) {
        for (int i = 1; i <= n; i += 2) {
            printf("%d ", i);
        }
    }
    else {
        for (int i = 2; i <= n; i += 2) {
            printf("%d ", i);
        }
    }
    cout << n - 3 << ' ' << n - 1 << ' ';
    for (int i = n - 5; i >= 1; i -= 2) {
        printf("%d ", i);
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}