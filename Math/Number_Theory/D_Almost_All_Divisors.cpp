#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    set<ll> st;
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        st.insert(1ll * v[i] * v[j]);
    }
    ll ans = -1;

    if (st.size() == 1) {
        ans = *st.begin();
        int cnt = 0;
        for (ll i = 2; i * i <= ans; i++) {
            if (ans % i)continue;
            cnt += 2;
            if (ans / i == i)cnt--;
        }
        if (cnt != n)ans = -1;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}