#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    //char res[3] = { 'F', 'M', 'S' };
    string res = "FMS";
    int p = 0, s = 0, r = 0;
    string ar[4] = {};
    for (int i = 0; i < 3; i++) {
        string st; cin >> st;
        ar[i] = st;

        if (st[0] == 's')s++;
        else if (st[0] == 'r')r++;
        else p++;
    }

    string ans = "";
    if (s == 1 && p == 2) ans = "scissors";
    else if (p == 1 && r == 2) ans = "paper";
    else if (r == 1 && s == 2) ans = "rock";
    else ans = '?';

    if (ans == "?")cout << ans;
    else {
        auto p = find(ar, ar + 3, ans) - ar;
        cout << res[p];
    }
    return 0;
}