#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n;i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n - 1 && k>0; i++) {
        if (v[i] < v[i + 1]) {
            k--;
            v[i]++;
            if (k <= 0) {
                cout << i + 1 << endl;
                return;
            }
            i = -1;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}