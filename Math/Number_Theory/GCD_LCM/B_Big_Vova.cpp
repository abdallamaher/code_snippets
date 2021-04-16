#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> ar(n), ans(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ar[i]);
        }

        int g = 0;
        for (int i = 0; i < n; i++) {
            int mx = 0, mxI = 0;
            for (int j = 0; j < n; j++) {
                if (ar[j] && __gcd(ar[j], g) >= mx) {
                    mx = __gcd(ar[j], g);
                    mxI = j;
                }
            }
            printf("%d ", ar[mxI]);
            g = __gcd(g, ar[mxI]);
            ar[mxI] = 0;
        }

        puts("");
    }
    return 0;
}