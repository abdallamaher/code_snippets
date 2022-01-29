#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; cin >> n >> k;
    set<int> st;
    int mx = 0, mex = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        st.insert(x);
        if (x > mx)mx = x;
    }
    for (int i = 0; i <= n + 1; i++)if (st.count(i) == 0) {
        mex = i;
        break;
    }
    if (k == 0) {
        cout << st.size() << endl;
    }
    else if (mx > mex) {
        // (mx + mex) / 2       mx/2 + mex/2 and mex>mx     so 1/2+1/2    (2 * mx + n) / 2  :)
        // number greater than mex
        // (5 + 2) / 2      = 4
        // (5 + 2) / 2      = 4
        cout << st.size() + (st.count( (int)ceil(1.0 * (mx + mex) / 2) ) == 0) << endl;
    }
    else if(mx < mex){
        // (mx + mex) / 2       mx/2 + mex/2 and mex<mx     so 1/2+1/2  :)
        // number greater than mx
        cout << st.size() + k << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}