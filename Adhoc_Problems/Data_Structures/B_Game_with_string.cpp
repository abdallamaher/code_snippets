#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long 

inline void solve() {
    string s; cin >> s;
    int lose = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == s[i + 1]) {
            s.erase(i, 2);
            if (!i)i++;
            i -= 2;
            lose = 1 - lose;
        }
    }
    puts(lose ? "Yes" : "No");
}

int main() {

    solve();
    return 0;

    string s; cin >> s;
    vector<char> v;
    int lose = 0;
    for (int i = 0; s[i]; i++) {
        if (v.size() && v.back() == s[i])v.pop_back(), lose = 1 - lose;
        else v.push_back(s[i]);
    }
    puts(lose ? "Yes" : "No");
}