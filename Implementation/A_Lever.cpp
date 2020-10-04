#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;
    int idx;
    for (int i = 0; s[i]; i++)
        if (s[i] == '^') {
            idx = i;
            break;
        }
    ll s1 = 0, s2 = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != '=' && s[i] != '^') {
            if (i < idx)
                s1 += 1ll * (idx - i) * (s[i] - '0');
            else
                s1 += 1ll * (idx - i) * (s[i] - '0');
        }
    }
    if (s1 == s2)
        puts("balance");
    else
        puts(s1 > s2 ? "left" : "right");
    return 0;
}