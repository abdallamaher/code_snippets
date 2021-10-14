#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    set<int> st;
    vector<int> v, dis;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (st.count(x) == 0)v.push_back(x);
        st.insert(x);
    }
    if (st.size() == 1) {
        cout << -1 << endl;
        return;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 1; i < v.size(); i++) {
        ans = __gcd(ans, abs(v[i] - v[i - 1]));
    }
    cout << ans << endl;
}

void go() {
    int n; cin >> n;
    int ar[n] = {};
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int g = 0;
    for (int i = 1; i < n; i++) {
        g = __gcd(g, abs(ar[i] - ar[i - 1]));
    }
    if (g == 0)cout << -1 << endl;
    else cout << g << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)go();
}