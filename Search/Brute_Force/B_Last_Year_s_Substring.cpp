#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

inline void solve() {
    int n; string s; cin >> n >> s;
    int ok = 0;
    for (int i = 0; i < 5; i++) {
        int j = 4 - i;
        string a = s.substr(0, i);
        string b = s.substr(n - j, j + 1);
        if (a + b == "2020")ok = 1;
    }
    puts(ok ? "YES" : "NO");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}