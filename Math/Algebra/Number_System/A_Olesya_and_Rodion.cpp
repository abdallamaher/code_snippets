#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, m; cin >> n >> m;
    if(n == 1 && m == 10){
        cout << -1 << endl;
        return;
    }
    cout << m;
    if (m == 10)n--;
    while (--n)cout << 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}