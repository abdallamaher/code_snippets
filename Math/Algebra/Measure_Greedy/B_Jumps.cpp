#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int x; cin >> x;
    int i = 0;
    while (i * (i + 1) < 2 * x)i++;
    // now you can dicrease 2 3 4 5 -- i
    if (i * (i + 1) / 2 == x + 1)cout << i + 1 << endl;
    else cout << i << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}