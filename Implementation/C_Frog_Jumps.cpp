#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        s = "#" + s + "R";

        int p = 0, ans = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == 'R')ans = max(ans, i - p), p = i;
        }

        printf("%d\n", ans);
    }
    return 0;
}