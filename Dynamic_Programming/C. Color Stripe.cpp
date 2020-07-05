#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
string s, st;
const int N = 5e5 + 5;
int dp[N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> s;
    if (k == 2) {
        string s1, s2;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                s1 += 'A';
                s2 += 'B';
            }
            else {
                s2 += 'A';
                s1 += 'B';
            }
            if (s1[i] != s[i])a++;
            if (s2[i] != s[i])b++;
        }
        if (a > b) printf("%d\n%s", b, s2.c_str());
        else printf("%d\n%s", a, s1.c_str());
        return 0;
    }
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (s[i - 1] == s[i - 2])dp[i] = i;
        else dp[i] = dp[i - 1];
    }

    st = "ABC";
    int p = dp[n], cnt = 0;
    while (p > 0) {
        cnt++;
        int ok = 0;
        for (auto c : st) {
            if (s[p - 3] != c && c != s[p - 1])ok = 1;
            if (ok) {
                s[p - 2] = c;
                break;
            }
        }
        p -= 2;
        p = dp[p];
    }
    printf("%d\n%s\n", cnt, s.c_str());
    return 0;
}

/*
6 2
ABAABA

1
ABAABA // wrong

*/