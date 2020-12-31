#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n, k; cin >> n >> k;
    int need[n + n] = {};
    for (int i = 0; i < n; i++)scanf("%d", need + i);
    int got[n + n] = {};
    for (int i = 0; i < n; i++) scanf("%d", got + i);
    int ans = 0;
    while (true) {
        int take = 0;
        for (int i = 0; i < n; i++) {
            if (got[i] >= need[i])got[i] -= need[i];
            else {
                take += need[i] - got[i];
                got[i] = 0;
            }
        }
        if (take <= k) ans++;
        k -= take;
        if (k < 0)break;
    }
    cout << ans << endl;
}