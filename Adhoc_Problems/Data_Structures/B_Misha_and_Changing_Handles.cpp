#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long 

int main() {
    int q; cin >> q;
    map<string, string> mp;
    while (q--) {
        string s, ss; cin >> s >> ss;
        int f = 0;
        for (auto& it : mp) {
            if (s == it.second) {
                it.second = ss;
                f = 1;
                break;
            }
        }
        if (!f)mp[s] = ss;
    }
    cout << mp.size() << endl;
    for (auto it : mp) {
        printf("%s %s\n", it.first.c_str(), it.second.c_str());
    }
}