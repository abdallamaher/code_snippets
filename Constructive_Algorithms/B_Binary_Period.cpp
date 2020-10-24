#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int p = 1;
        for (int i = 1;i < s.size(); i++) {
            if (s[i] != s[0])p = 2;
        }
        if (p == 1) {
            cout << s << endl;
            continue;
        }
        string st(2 * s.size(), '0');
        for (int i = 1; i < st.size(); i += 2) {
            st[i] = '1';
        }
        cout << st << endl;
    }

    return 0;
}