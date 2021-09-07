#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; cin >> n;

    // cout << __builtin_popcount(n) << endl;

    int ans = 0;
    for (int i = 0; i < 30; ++i) {
        if (n & (1 << i))ans++;
    }
    cout << ans << endl;
}