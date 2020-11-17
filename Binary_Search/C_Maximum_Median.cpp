#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k;
vector<int> v;

bool can(ll x) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += max(0ll, x - v[i]);
    }
    return res <= k;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    v = vector<int>(v.begin() + n / 2, v.end());
    n = v.size();
    ll st = v[0], en = 1e12, mid;
    while (st < en) {
        mid = (st + en + 1) >> 1;
        if (can(mid)) st = mid;
        else en = mid - 1;
    }
    printf("%lld\n", en);
    return 0;
}