#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(string& s) {
    int res = 0;
    for (auto& c : s) {
        if (c == '(')res++;
        else res--;

        if (res < 0)return 0;
    }
    return res == 0;
}

inline void solve() {
    string s; cin >> s;
    int n = s.size();
    int flag = 0;
    for (int mask = 0; mask < (1 << 3); mask++) {
        string t = "";
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            if (mask & (1 << c)) t += '(';
            else t += ')';
        }
        flag |= check(t);
    }
    if (flag == 1)cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}