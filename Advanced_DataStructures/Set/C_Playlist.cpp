#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 3e5 + 5;
pair<ll, ll> ar[N];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d%d", &a, &b);
        ar[i] = { b, a };
    }
    sort(ar, ar + n);
    reverse(ar, ar + n);

    ll ans = 0, cur = 0;
    multiset<pair<ll, ll>> st;

    for (int i = 0; i < n; i++) {
        st.insert({ ar[i].second, ar[i].first });
        cur += ar[i].second;
        while (st.size() > k) {
            auto p = st.begin();
            cur -= p->first;
            st.erase(p);
        }

        ans = max(ans, cur * ar[i].first);
    }
    printf("%lld\n", ans);
}