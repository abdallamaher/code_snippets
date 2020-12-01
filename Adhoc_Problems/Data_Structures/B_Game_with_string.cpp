#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long 

int main() {
    string s; cin >> s;
    vector<char> v;
    int lose = 0;
    for (int i = 0; s[i]; i++) {
        if (v.size() && v.back() == s[i])v.pop_back(), lose = 1 - lose;
        else v.push_back(s[i]);
    }
    puts(lose ? "Yes" : "No");
}