#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> v;
set<pair<int, int>> se;
string s, ans;
char t;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s; v.push_back(s);
    } cin >> s >> t;

    for (int i = 0; i < n; i++) {
        for (int ii = 0; ii < s.size(); ii++) {
            for (int j = 0; j < v[i].size(); ) {
                if (tolower(s[ii+j]) == tolower(v[i][j])) {
                    j++;
                }
                else {
                    break;
                }
                if (j == v[i].size()) {
                    se.insert({ ii, ii + j });
                    break;
                }
            }
        }
    }
    ans = s;
    for (auto it: se) {
        for (int ii = it.first; ii < it.second; ii++) {
            if (tolower(s[ii]) == t && t != 'a')ans[ii] = s[ii] >= 'a' ? 'a' : 'A';
            if (tolower(s[ii]) == t && t == 'a')ans[ii] = s[ii] >= 'a' ? 'b' : 'B';
            if (tolower(s[ii]) != t)ans[ii] = s[ii] >= 'a' ? t : t-32;
        }
    }
    cout << ans;
    return 0;
}