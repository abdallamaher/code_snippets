#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int n, ans;
bool check(int i, int j) {
    int len = (j - i + 1);
    if (len & 1)return 0;
    len /= 2;
    for (int a = i; a < j; a++) {
        if (a + len > j)break;
        else if (s[a+len] == '#')continue;
        else if (s[a] != s[a + len])return 0;
    }
    return 1;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s >> n;
    for (int i = 0; i < n; i++) { s += '#'; }
    n = s.length();
    ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (check(i, j))ans = max(ans, j - i + 1);
        }
    }
    cout << ans;
    return 0;
}
