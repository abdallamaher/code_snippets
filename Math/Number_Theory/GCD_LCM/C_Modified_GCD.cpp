#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int x, y, q; cin >> x >> y >> q;
    int g = gcd(x, y);
    vector<int> div;
    for (int i = 1; 1ll * i * i <= g; i++) {
        if (g % i)continue;
        div.push_back(i);
        if (g != i * i)div.push_back(g / i);
    }
    sort(div.begin(), div.end());
    while (q--) {
        int a, b; cin >> a >> b;
        // int mx = 0;
        // for (auto it : div) {
        //     if (it >= a && it <= b)mx = max(mx, it);
        // }
        // cout << (mx ? mx : -1) << endl;
        auto pos = lower_bound(div.begin(), div.end(), b);
        if (pos == div.end() || *pos > b) pos--;
        
        if (*pos >= a && *pos <= b) cout << *pos << endl;
        else cout << -1 << endl;
    }
}