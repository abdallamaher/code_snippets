#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> v(n + n);
    vector<int> cnt(n + n), a(q + q), b(q + q);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }
    for (int i = 0; i < q;i++) {
        scanf("%d%d", &a[i], &b[i]);
        a[i]--, b[i]--;
        cnt[a[i]]++, cnt[b[i] + 1]--;
    }
    vector<pair<int, int>> good(n + n);
    for (int i = 0; i < n; i++) {
        if (i)cnt[i] += cnt[i - 1];
        good[i] = { cnt[i], i };
    }


    sort(good.begin(), good.begin() + n);
    sort(v.begin(), v.begin() + n);


    for (int i = 0; i < n; i++) {
        good[i].first = v[i];
    }
    for (int i = 0; i < n; i++) {
        v[good[i].second] = good[i].first;
    }


    ll sum = 0;
    for (int i = 1;i < n; i++)v[i] += v[i - 1];

    for (int i = 0; i < q;i++) {
        sum += v[b[i]];
        if (a[i])sum -= v[a[i] - 1];
    }
    cout << sum << endl;
}

int main() {
    int n, q; cin >> n >> q;
    vector<int> v(n + n), cnt(n + n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < q;i++) {
        int a , b; scanf("%d%d", &a, &b);
        cnt[a - 1]++, cnt[b]--;
    }
    for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
    }


    sort(cnt.begin(), cnt.begin() + n);
    sort(v.begin(), v.begin() + n);

    ll sum = 0;
    for (int i = 0; i < n;i++) {
        sum += 1ll * v[i] * cnt[i];
    }
    cout << sum << endl;
}