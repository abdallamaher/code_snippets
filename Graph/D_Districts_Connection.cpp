#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> v(n);
    set<int> st;
    for (int i = 0; i < n;i++) {
        int x; cin >> x;
        st.insert(x);
        v[i] = x;
    }
    if (st.size() == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] != v[0]) {
            cout << i + 1 << ' ' << 1 << endl;
            idx = i + 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (v[i] == v[0])
            cout << idx << ' ' << i + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}