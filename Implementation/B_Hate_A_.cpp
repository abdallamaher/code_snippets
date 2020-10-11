#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t; cin >> t;
    int x = 0, y = 0;
    for (int i = t.size() - 1, f = 0; i >= 0;i--) {
        if (f || t[i] == 'a') {
            if (t[i] != 'a')y++;
            f = 1;
        }
        else x++;
    }
    
    for (auto c : t) if (c != 'a')s.push_back(c);

    if (y <= x && s.size() % 2 == 0) {
        int ok = 1;
        for (int i = s.size() / 2, j = 0; i < s.size(); j++, i++) {
            if (s[i] != s[j])ok = 0;
        }
        if (ok) {
            for (int i = 0; i < t.size() - s.size() / 2; i++) {
                cout << t[i];
            }
            return 0;
        }
    }
    cout << ":(";
    return 0;
}