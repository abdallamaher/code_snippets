#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; scanf("%d", &n);
    int ar[9] = {};
    int ans = 0;
    while (n--) {
        string s; cin >> s;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '1')ar[i]++;
            ans = max(ans, ar[i]);
        }
    }
    printf("%d", ans);
    return 0;
}