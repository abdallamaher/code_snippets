#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        string a(n, '0'), b(n, '0');
        int f = 0;
        for (int i = 0; s[i]; i++) {
            if (f)a[i] = s[i], b[i] = '0';
            else if (s[i] == '0') a[i] = '0', b[i] = '0';
            else if (s[i] == '1') a[i] = '0', b[i] = '1', f = 1;
            else if (s[i] == '2') a[i] = '1', b[i] = '1';
        }
        for (auto c : a) cout << c;
        cout << '\n';
        for (auto c : b) cout << c;
        cout << '\n';
    }
    return 0;
}