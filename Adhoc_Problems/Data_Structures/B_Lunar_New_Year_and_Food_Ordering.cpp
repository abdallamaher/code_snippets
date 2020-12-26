#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Data {
    ll idx = 0;
    ll cnt = 0;
    ll cost = 0;
};

int main() {
    ll n, m; cin >> n >> m;
    vector<Data> data;
    for (ll i = 0; i < n;i++) {
        ll x; scanf("%lld", &x);
        data.push_back({ i, x, 0 });
    }
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &data[i].cost);
    }

    sort(data.begin(), data.end(), [](Data f, Data s) {
        if (f.cost != s.cost) return f.cost < s.cost;
        return f.idx < s.idx;
        });
    map<ll, ll>get;
    for (ll i = 0; i < n;i++) {
        get[data[i].idx] = i;
    }
    ll st = 0;
    for (ll i = 0; i < m; i++) {
        ll idx, need; scanf("%lld%lld", &idx, &need);
        idx--;
        idx = get[idx];

        ll mn = min(data[idx].cnt, need);
        data[idx].cnt -= mn;
        need -= mn;
        ll ans = 1ll * mn * data[idx].cost;

        while (need > 0 && st < n) {
            mn = min(data[st].cnt, need);
            data[st].cnt -= mn;
            need -= mn;
            ans += 1ll * mn * data[st].cost;
            if (data[st].cnt == 0)st++;
        }
        if(need)ans = 0;
        printf("%lld\n", ans);
    }
}



set<pair<pair<int, int>, int>> st;
inline ll go(pair<pair<int, int>, int> cur, int& need) {
    st.erase(cur);
    int mn = min(need, cur.second);
    need -= mn;
    cur.second -= mn;
    if (cur.second > 0)st.insert(cur);
    return 1ll * mn * cur.first.first;
}

int solve() {
    ll n, m; cin >> n >> m;
    int cnt[n], cost[n];
    for (ll i = 0; i < n;i++) {
        cin >> cnt[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> cost[i];
        st.insert({ {cost[i], i}, cnt[i] });
    }
    while (m--) {
        int i, need; cin >> i >> need;
        i--;
        auto cur = *st.lower_bound({ {cost[i], i}, -1 });
        ll ans = 0;
        if (cur.first.second == i)ans += go(cur, need);
        while (need > 0) {
            if (st.empty()) {
                ans = 0;
                break;
            }
            cur = *st.begin();
            ans += go(cur, need);
        }
        cout << ans << endl;
    }
}