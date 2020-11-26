#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        int ok = 1;
        int x = 0, y = 0;
        while (n--) {
            int a, b; scanf("%d %d", &a, &b);
            // if not succeed from first time, can't use this player again
            if (a < b || a < x || b < y || a - x < b - y) ok = 0;
            x = a, y = b;
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}