#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    map<char, string> mp;
    mp['2'] = "2";
    mp['3'] = "3";
    mp['4'] = "322";
    mp['5'] = "5";
    mp['6'] = "35";
    mp['7'] = "7";
    mp['8'] = "7222";
    mp['9'] = "3372";

    int n; cin >> n;
    string s; cin >> s;
    string ans;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '1' || s[i] == '0')continue;
        ans += mp[s[i]];
    }
    sort(ans.rbegin(), ans.rend());
    cout << ans << endl;
}