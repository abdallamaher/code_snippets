#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, sp, a, b; cin >> n >> sp >> a >> b;
    int res = 1e9 + 5;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i + sp * j >= n) res = min(res, i * a + j * b);
        }
    }
    cout << res << '\n';
    return 0;


    int ans = 0;
    int x = n / sp;
    if (sp * a > b) ans = x * b;
    else ans = x * sp * a;

    x = n % sp;
    if (a * x > b)ans += b;
    else ans += x * a;

    cout << ans << '\n';
    return 0;
}