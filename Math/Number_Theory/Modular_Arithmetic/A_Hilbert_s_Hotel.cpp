#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; scanf("%d", &n);
    int ok = 1;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        x = ( (x + i) % n + n ) % n;    //mod for negative numbers
        st.insert(x);
    }
    puts(st.size() == n ? "YES" : "NO");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}