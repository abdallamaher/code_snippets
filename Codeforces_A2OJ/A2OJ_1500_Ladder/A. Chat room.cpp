#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
string h = "hello";

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    int j = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == h[j])
            j++;
    }
    if (j == 5)cout << "YES";
    else cout << "NO";
    return 0;
}