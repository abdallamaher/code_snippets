#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string a(n, '0'), b(n, '0');
    for (int i = 0;i < n; i++) {
        if (s[i] == '1') {
            a[i] = '1';
            for (int j = i + 1;j < n; j++)b[j] = s[j];
            break;
        }
        else {
            a[i] = b[i] = '0' + (s[i] - '0') / 2;
        }
    }
    cout << a << endl << b << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}