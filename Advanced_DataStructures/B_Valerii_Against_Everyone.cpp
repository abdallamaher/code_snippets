#include <bits/stdc++.h>
using namespace std;
#define ll long long 

inline void solve() {
    int n; cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        s.insert(x);
    }
    puts(s.size() != n ? "YES" : "NO");
}


int main() {
    int t; cin >> t;
    while (t--)solve();
    return 0;
}