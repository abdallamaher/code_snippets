#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    string s;
    cin >> n >> s;
    if (n % 4) return cout << "===", 0;  // 5 AAAAA
    n /= 4;
    map<char, int> mp;
    mp['A'] = n, mp['G'] = n, mp['C'] = n, mp['T'] = n;

    for (auto c : s) {
        if (c != '?') {
            mp[c]--;
        }
        if (mp[c] < 0) return cout << "===", 0;
    }

    for (int i = 0; s[i]; i++) {  // 4 A???
        if (s[i] != '?') continue;
        for (auto &it : mp) {
            if (it.second) {
                s[i] = it.first;
                it.second--;
                break;
            }
        }
        if (s[i] == '?') return cout << "===", 0;
    }

    cout << s << endl;
    return 0;
}