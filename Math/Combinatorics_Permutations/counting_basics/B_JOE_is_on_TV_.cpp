#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    ld ans = 0;
    for (int i = 1; i <= n; i++)ans += (ld)1 / i;
    cout << fixed << setprecision(15) << ans << endl;
}