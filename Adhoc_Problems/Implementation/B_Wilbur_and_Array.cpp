#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    int p = 0; ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        ans += abs(x - p);
        p = x;
    }
    cout << ans << '\n';
    return 0;
}