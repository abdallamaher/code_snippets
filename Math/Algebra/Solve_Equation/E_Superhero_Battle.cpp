#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 2e5 + 5;
ll ar[mxN];
ll H, n, total, lst_cycle, ans;

int main() {
    cin >> H >> n;
    for (int i = 0; i < n; i++) {
        scanf("%lld", ar + i);
        total += ar[i];
        lst_cycle = min(lst_cycle, total);
    }

    // H = qu * x + lst_cycle;

    lst_cycle = abs(lst_cycle);
    if (H > lst_cycle) {
        if (total >= 0) {
            puts("-1");
            return 0;
        }
        
        ll rem_cycles = H - lst_cycle;
        total = abs(total);
        ll qu = ceil(1.0 * rem_cycles / total);//  1/2  so take one total to  cover it
        
        H -= qu * total;
        ans += qu * n;
    }

    for (int i = 0; i < n; i++) {
        ans++;
        H += ar[i];
        if (H <= 0)break;
    }

    cout << ans << endl;
}