#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    for (int i = 0; i < 9; i++) {
        string s; cin >> s;
        for (auto& c : s)if (c == '1')c = '2';
        cout << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}