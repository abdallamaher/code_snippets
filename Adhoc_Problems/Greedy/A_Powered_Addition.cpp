#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

inline void solve() {
    int n; cin >> n;
    vector<int> v(n + n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    int mx = 0;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] > v[i]) {
            mx = max(mx, v[i - 1] - v[i]);
            v[i] = v[i - 1];
        }
    }
    cout << (int)ceil(log(mx + 1) / log(2)) << endl;    // (mx + 1)   any number in [2 : 4] like 3 : we can form with 2^0 + 2^1 = 1+2 = 3
}

inline void go() {
    int n; cin >> n;
    vector<int> v(n + n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    int ans = 0;
    for (int i = 1; i < n;i++) {
        int k = v[i - 1] - v[i];
        int x = 0;
        while (k > 0) {
            k -= (1ll << x);
            x++;
        }
        ans = max(ans, x);
        v[i] = max(v[i], v[i - 1]);
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)go();
}