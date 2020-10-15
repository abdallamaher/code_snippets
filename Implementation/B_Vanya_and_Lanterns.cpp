#include <bits/stdc++.h>
using namespace std;
#define ld long double

int main() {
    int n, l; cin >> n >> l;
    vector<int> v(n);
    for (auto& it : v)scanf("%d", &it);
    sort(v.begin(), v.end());
    int a = 0, b = max(v[0], l - v[n - 1]);
    for (int i = 1; i < n; i++) {
        a = max(a, v[i] - v[i - 1]);
    }
    long double ans = max(a / 2.0L, 1.0L * b);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}