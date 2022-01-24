#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, d; cin >> n >> d;

    // int lm = min(d, (int)1e6);

    int lm = sqrt(d);
    /*
    num = x * y
    num/x = y
    num/y = x
    so num/x + x == y + x
    z + ceil(u) = ceil(z + u);
    so >>
    */

    for (int x = 0; x <= lm; x++) {
        if (x + (d + x) / (x + 1) <= n) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO" << endl;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}