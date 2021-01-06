#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int ar[20] = {};
    int mn = 0;
    for (int i = 0; i < 10;i++) {
        scanf("%d", ar + i);
        if (ar[i] < ar[mn]) {
            mn = i;
        }
        if (mn == 0 && ar[i] <= ar[mn]) {
            mn = i;
        }
    }
    if (mn == 0) {
        cout << 1 << string(ar[0] + 1, '0') << endl;
    }
    else cout << string(ar[mn] + 1, char(mn + '0')) << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}