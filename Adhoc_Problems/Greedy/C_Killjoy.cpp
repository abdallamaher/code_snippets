#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; scanf("%d %d", &n, &k);
    int cnt = 0, big = 0, small = 0;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        if (x == k)cnt++;
        else if (x > k)big += abs(x - k);
        else small += abs(x - k);
    }
    if (cnt == n)cout << 0;
    else if (cnt || big == small)cout << 1;
    else cout << 2;
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}