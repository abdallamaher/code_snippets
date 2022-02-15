#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        auto p = st.lower_bound(x);
        if (p == st.end()) {
            st.insert(x);
        }
        else {
            int mx;
            while (p != st.end()) {
                mx = *p;
                p = st.erase(p);
            }
            st.insert(mx);
        }
    }
    cout << st.size() << endl;
}

void run() {
    int n; cin >> n;
    int ans = n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        int mn = v[i];
        while (st.size() && v[i] > st.top()) {
            mn = min(mn, st.top());
            st.pop();
            ans--;
        }
        st.push(mn);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)run();
}