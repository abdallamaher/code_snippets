#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
const int N = 1e5 + 5;
int upper[N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    int n = s.size(), ans = 1e9;
    for (int i = n - 1; i >= 0; i--) {
            upper[i] = upper[i + 1] + bool(isupper(s[i]));
    }
    int lowerN = 0;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, upper[i] + lowerN);
        if (i < n && islower(s[i]))lowerN++;
    }
    cout << ans;
    return 0;
}

