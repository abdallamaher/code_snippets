#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            sum += x;
        }
        puts(sum == m ? "YES" : "NO");
    }

    return 0;
}