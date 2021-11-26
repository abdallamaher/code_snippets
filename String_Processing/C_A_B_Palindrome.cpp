#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int a, b; string s;
    cin >> a >> b >> s;
    int f = 1;
    int n = a + b;
    if (n & 1) {
        if (s[n / 2] == '?') {
            if (a & 1)s[n / 2] = '0';
            else if (b & 1)s[n / 2] = '1';
            else f = 0;
        }
    }
    a -= count(s.begin(), s.end(), '0');
    b -= count(s.begin(), s.end(), '1');
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if ((s[i] == '1' || s[j] == '1') && (s[i] == '?' || s[j] == '?')) {
            if (b) {
                b--;
                s[i] = s[j] = '1';
            }
            else {
                f = 0;
                break;
            }
        }

    }

    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if ((s[i] == '0' || s[j] == '0') && (s[i] == '?' || s[j] == '?') && a) {
            if (a) {
                a--;
                s[i] = s[j] = '0';
            }
            else {
                f = 0;
                break;
            }
        }
    }
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
            f = 0;
            break;
        }
        else if (s[i] == '?' && s[j] == '?') {
            if (a > 1) {
                s[i] = s[j] = '0';
                a -= 2;
            }
            else if (b > 1) {
                s[i] = s[j] = '1';
                b -= 2;
            }
            else {
                f = 0;
                break;
            }
        }
    }
    if (!f || a || b) {
        cout << -1 << endl;
    }
    else {
        cout << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}