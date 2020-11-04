#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n;scanf("%d", &n);
    vector<int> ar(n + 5), vis(n + 5);
    for (int i = 1; i <= n;i++) {
        int x; scanf("%d", &x);
        ar[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int j = i;
            vector<int> st;
            while (!vis[j]) {
                st.push_back(j);
                vis[j]++;
                j = ar[j];
            }
            for (auto it : st) vis[it] = st.size();
            st.clear();
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", vis[ar[i]]);
    }
    puts("");
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}