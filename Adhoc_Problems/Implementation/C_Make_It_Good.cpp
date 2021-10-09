#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    int ar[n] = {};
    for (int i = 0; i < n;i++) {
        cin >> ar[i];
    }
    int pos = n - 1;
    while (pos > 0 && ar[pos - 1] >= ar[pos])pos--;
    while (pos > 0 && ar[pos - 1] <= ar[pos])pos--;
    cout << pos << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}