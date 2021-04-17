#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int q, k; scanf("%d %d", &q, &k);
    set<pair<int, int>> s;
    for (int i = 0; i < k; i++)s.insert({ 0, i });
    int cnt[k] = {};
    while (q--) {
        int x; scanf("%d", &x);
        x %= k;
        s.erase({ cnt[x], x });
        cnt[x]++;
        s.insert({ cnt[x], x });
        auto bgn = *s.begin();
        printf("%lld\n", bgn.second + 1ll * k * bgn.first);
    }
}