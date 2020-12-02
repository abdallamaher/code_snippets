#include <bits/stdc++.h>
using namespace std;
#define ll long long 

inline void go() {
    string s; cin >> s;
    for (auto& it : s)it -= '0';
    vector<int> ans;
    int tmp = 0;
    while (count(s.begin(), s.end(), 0) < s.size()) {
        tmp = 0;
        for (int i = 0; i < s.size(); i++) {
            tmp = tmp * 10 + bool(s[i]);
            if (s[i])s[i]--;
        }
        ans.push_back(tmp);
    }
    cout << ans.size() << endl;
    for (auto it : ans)printf("%d ", it);
}


int main() {
    int n; cin >> n;
    vector<int> ans;
    while (n) {
        int tmp = n, m = 0, p = 1;
        while (tmp) {
            if (tmp % 10)m += p;
            tmp /= 10;
            p *= 10;
        }
        ans.push_back(m);
        n -= m;
    }
    cout << ans.size() << endl;
    for (auto it : ans)printf("%d ", it);
}