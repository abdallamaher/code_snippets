#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> ar(n + 2);
        int mx = -1e9, mxI = -1;
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            ar[i] = x;
            if (x > mx)mx = x;
        }
        ar[0] = 1e9 + 5, ar[n+1] = 1e9 + 5;
        for (int i = 1;i <= n;i++) {
            if (ar[i] == mx && (ar[i + 1] < mx || ar[i - 1] < mx))mxI = i;
        }
        cout << mxI << '\n';

    }

    return 0;
}