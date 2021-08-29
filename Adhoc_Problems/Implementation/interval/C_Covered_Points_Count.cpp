#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5 + 5;
pair<ll, ll> ar[N];
vector<ll> store;
ll sum[N], ans[N];
ll n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll l, r; scanf("%lld %lld", &l, &r);
        ar[i].first = l;
        ar[i].second = r;
        store.push_back(l);
        store.push_back(r + 1);
    }

    sort(store.begin(), store.end());
    store.resize(unique(store.begin(), store.end()) - store.begin());

    for (int i = 0; i < n; i++) {
        auto p = ar[i];
        auto l = lower_bound(store.begin(), store.end(), p.first) - store.begin();
        auto r = lower_bound(store.begin(), store.end(), p.second + 1) - store.begin();
        sum[l]++;
        sum[r]--;
    }

    for (int i = 1; i < 2 * n; i++) {
        sum[i] += sum[i - 1];
    }

    for (int i = 1;i < 2 * n; i++) {
        ans[sum[i - 1]] += store[i] - store[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }

    return 0;
}