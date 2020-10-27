#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int r, l;cin >> l >> r;
        if (l < (r + 1) / 2.0)puts("NO");
        else puts("YES");
    }

    return 0;
}