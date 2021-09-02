#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    if (n == 2) {
        cout << "-1\n";
        return;
    }
    vector<int> ar(n * n);
    int cnt = 1;
    for (int i = 0; i < n * n;i += 2) {
        ar[i] = cnt;
        cnt++;
    }
    for (int i = 1; i < n * n; i += 2) {
        ar[i] = cnt;
        cnt++;
    }
    for (int i = 0; i < n * n;i++) {
        cout << ar[i] << ' ';
        if ((i + 1) % n == 0)cout << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}