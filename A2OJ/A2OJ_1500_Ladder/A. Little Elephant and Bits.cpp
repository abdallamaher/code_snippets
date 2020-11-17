#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
string s, ss;
int f;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '0' && !f) {
            f ^= 1;
            continue;
        }
        ss += s[i];
    }
    if (!f)ss.pop_back();
    cout << ss;
    return 0;
}