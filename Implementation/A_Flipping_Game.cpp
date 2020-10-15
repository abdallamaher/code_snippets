#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        sum[i] = x + sum[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int o = sum[j] - sum[i - 1];
            int z = j - i + 1 - o;
            ans = max(ans, sum[n] + z - o);
        }
    }
    cout << ans << '\n';
    return 0;
}