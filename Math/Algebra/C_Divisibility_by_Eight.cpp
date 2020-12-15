#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    string s; cin >> s;
    for (auto& it : s)it -= '0';
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] % 8 == 0) {
            return printf("YES\n%d\n", s[i]), 0;
        }
        for (int j = i + 1; j < n; j++) {
            if ((s[i] * 10 + s[j]) % 8 == 0) {
                return printf("YES\n%d\n", s[i] * 10 + s[j]), 0;
            }
            for (int x = j + 1; x < n; x++) {
                if ((s[i] * 100 + s[j] * 10 + s[x]) % 8 == 0) {
                    return printf("YES\n%d\n", s[i] * 100 + s[j] * 10 + s[x]), 0;
                }
                // if ((s[i] & 1 ^ 1 && (s[j] * 10 + s[x]) % 8 == 0) ||
                //     (s[i] & 1 && (s[j] * 10 + s[x] + 4) % 8 == 0)) {
                //     return printf("YES\n%d\n", s[i] * 100 + s[j] * 10 + s[x]), 0;
                // }
            }
        }
    }
    puts("NO");
}