#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll k, a, b; cin >> k >> a >> b;
    ll ans = 0;

    if (a <= 0 && b >= 0) {
        ans = abs(a) / k + abs(b) / k + 1;
    }
    else {
        a = abs(a);
        b = abs(b);
        if (a > b)swap(a, b);
        ans = b / k - (a - 1) / k;
    }
    cout << ans << endl;
}
