#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, a, b;

ll solve(int x) {
    if (x == 1)return 0;
    if (x < k || k == 1)return a * (x - 1);

    if (x % k) {
        ll t = k * (x / k);
        return solve(t) + (x - t) * a;
    }
    else {
        ll t = x / k;
        return solve(t) + ((x - t) * a > b ? b : (x - t) * a);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> a >> b;
    cout << solve(n) << endl;
    return 0;
}