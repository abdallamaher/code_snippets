#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; string s;
    cin >> n >> s;
    int ok = (s[0] == '1' && s[n - 1] == '1'), zeros = 0, ones = 0;
    for (auto c : s) {
        zeros += (c - '0');
    }
    if (zeros & 1 || ok == 0) {
        cout << "NO\n";
        return;
    }
    string s1(n, ' '), s2(n, ' ');
    s1[0] = s2[0] = '(';
    s1[n - 1] = s2[n - 1] = ')';
    ones = 0, zeros = 0;
    for (int i = 1;i < n - 1; i++) {
        if (s[i] == '0') {
            if (zeros)s1[i] = '(', s2[i] = ')', zeros = 1 - zeros;
            else s2[i] = '(', s1[i] = ')', zeros = 1 - zeros;
        }
        else {
            if (ones)s1[i] = ')', s2[i] = ')', ones = 1 - ones;
            else s2[i] = '(', s1[i] = '(', ones = 1 - ones;
        }
    }
    puts("YES");
    cout << s1 << '\n' << s2 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}