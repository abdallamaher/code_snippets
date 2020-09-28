#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int f = 1, cnt = 1;
    for (int i = 1; s[i]; i++) {
        if (s[i] == s[i - 1])
            ++cnt;
        else
            cnt = 1;
        if (cnt >= 7) f = 0;
    }
    puts(!f ? "YES" : "NO");
    return 0;
}