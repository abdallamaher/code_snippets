#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    ll hei[n] = {};
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> hei[i];
        if (hei[i] > mx)mx = hei[i];
        else hei[i] = mx;
    }

    int m; cin >> m;
    while (m--) {
        int w, h; cin >> w >> h;
        ll ans = max(hei[0], hei[w - 1]);
        cout << ans << endl;
        hei[0] = ans + h;
    }
}