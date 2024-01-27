#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> ar(n);
    set<int> st;
    for (auto& it : ar) {
        cin >> it;
        st.insert(it);
    }

    for (int mask = 1; mask < 1024; ++mask) {
        for (int i = 0; i < n; i++) {
            int x = mask ^ ar[i];
            if (!st.count(x))break;
            if (i == n - 1) {
                cout << mask << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}