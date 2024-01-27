#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n;cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n; i++)cin >> v[i];
    int st = 1, en = 1;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            int j = i + 1;
            while (j < n && v[j - 1] > v[j]) {
                j++;
            }
            st = i + 1, en = j;
            reverse(v.begin() + i, v.begin() + j);
            break;
        }
    }
    int f = 1;
    for (int i = 1; i < n; i++)f &= (v[i - 1] < v[i]);
    if (f) {
        cout << "yes\n" << st << ' ' << en << endl;
    }
    else {
        cout << "no\n" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}