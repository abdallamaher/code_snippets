#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt = 0, ok = 1;
    for (int i = 0;s[i]; i++) {
        if (s[i] == '#')cnt++;
        else cnt = 0;

        if (cnt == k)ok = 0;
    }
    puts(ok ? "YES" : "NO");
    return 0;
}