#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    string s; cin >> s;
    for (int i = 0; s[i]; i++) {
        if (!i && s[i] == '9')continue;
        if (s[i] > '4') s[i] = '9' - s[i] + '0';
    }
    cout << s;
    return 0;
}