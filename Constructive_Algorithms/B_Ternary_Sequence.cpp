#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int z, o, t, zz, oo, tt;
        scanf("%d%d%d %d%d%d", &z, &o, &t, &zz, &oo, &tt);
        
        
        ll sum = min(t, oo) * 2;
        t -= min(t, oo);

        tt -= min(tt, z);
        tt -= min(tt, t);

        sum -= 2 * tt;

        cout << sum << '\n';
    }

    return 0;
}