#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n), ans(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    k--;
    for (int i = k, j = 0; i < n; i++, j++) {
        ans[j] += v[i];
    }
    for (int i = k, j = 0; i >= 0; i--, j++) {
        ans[j] += v[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // cout << i << ' ' << ans[i] << endl;
        if (i <= min(k, n - k - 1)) {
            if (!i && ans[i])cnt++;
            else if (ans[i] == 2)cnt += 2;
        }
        else if (ans[i])cnt++;
    }
    cout << cnt << '\n';
    return 0;
}