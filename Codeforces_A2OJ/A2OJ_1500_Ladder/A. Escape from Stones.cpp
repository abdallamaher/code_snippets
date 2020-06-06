#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;
vector<int> r, l;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'l')l.push_back(i + 1);
        else r.push_back(i + 1);
    }
    for (auto it : r)cout << it << "\n";
    for (auto it = l.rbegin(); it != l.rend(); it++)cout << *it << "\n";
    
    return 0;
}