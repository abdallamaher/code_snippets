#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll p, f, cnt_s, cnt_w, s, w;
    scanf("%lld%lld%lld%lld%lld%lld", &p, &f, &cnt_s, &cnt_w, &s, &w);

    if (s > w) {
        swap(s, w);
        swap(cnt_s, cnt_w);
    }

    ll  best = 0;
    for (ll i = 0; i <= cnt_s; i++) if (i * s <= p) {
        ll best_me_w = min((p - i * s) / w, cnt_w);
        ll best_me = i + best_me_w;

        ll rem_s = cnt_s - i;
        ll rem_w = cnt_w - best_me_w;

        ll best_f = 0;
        if (rem_s * s >= f) {
            best_f = f / s;
        }
        else {
            best_f = rem_s + min(rem_w, (f - rem_s * s) / w);
        }

        best = max(best, best_me + best_f);
    }
    printf("%lld\n", best);
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}