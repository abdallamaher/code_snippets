#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mx, c; cin >> n >> mx >> c;
    vector<int> v(n + 1);
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        if (v[i] <= mx)cnt++;
        else cnt = 0;

        if (cnt == c)cnt--, ans++;
    }
    cout << ans << '\n';
    return 0;
}