#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> ar(n);
    for (auto& it : ar)cin >> it;
    cout << 0 << ' ';
    int pre = ar[0];
    for (int i = 1;i < n; i++) {
        int x = ar[i];
        int y = (pre | x) ^ x;  // one in pre and not in x should be in y
        cout << y << ' ';
        pre = y ^ x;
    }
    cout << endl;
}

inline void go() {
    int n; cin >> n;
    vector<int> ar(n);
    for (auto& it : ar)cin >> it;
    cout << 0 << ' ';
    int pre = ar[0];
    for (int i = 1;i < n; i++) {
        int x = ar[i];
        int y = 0;
        for (int i = 0; i < 32; i++) {
            if (pre & (1 << i)) {
                if ((x & (1 << i)) == 0)y |= (1 << i);
            }
        }
        pre = y ^ x;
        cout << y << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}