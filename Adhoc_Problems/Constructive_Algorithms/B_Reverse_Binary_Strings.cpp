#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<char> v;
        for (int i = 1, cnt = 1; i < n; i++) {
            if (s[i] == '1' && s[i-1] == '1')v.push_back(i);
        }
        int ans = v.size();
        v.clear();
        for (int i = 1, cnt = 1; i < n; i++) {
            if (s[i] == '0' && s[i-1] == '0')v.push_back(i);
        }
        cout << max(ans, (int)v.size()) << endl;
    }

    return 0;
}