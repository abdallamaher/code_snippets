#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    string s; cin >> s;
    int n = s.size();
    for (auto& it : s)it -= '0';
    
    int ok = 0;
    for (auto it : s)ok |= (it % 2 == 0);
    if (ok == 0)return puts("-1"), 0;

    for (int i = 0; i < n; i++) {
        if (s[i] < s[n - 1] && s[i] % 2 == 0) {
            swap(s[i], s[n - 1]);
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] % 2 == 0) {
            swap(s[i], s[n - 1]);
            break;
        }
    }

    for (auto& it : s)cout << char(it + '0');
    return 0;
}