#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, a, b, k;
    scanf("%d %d %d %d", &n, &a, &b, &k);
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h[i]);
        h[i] %= a + b;
        if (h[i] == 0) h[i] += a + b;
        // how to finish rem with a     ceil(rem/a)      -1 as you start
        h[i] = ((h[i] + a - 1) / a) - 1;
    }
    // for (auto it : h)cout << it << ' '; cout << endl;
    sort(h.begin(), h.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (k - h[i] < 0) break;
        ++ans;
        k -= h[i];
    }

    cout << ans << endl;

}