#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    string s; cin >> s;
    s += s;
    int ans = 0, n = s.size();
    for (int i = 1, cnt = 1; i < n; i++) {
        if (s[i] != s[i - 1])cnt++;
        else cnt = 1;

        ans = max(ans, cnt);
    }

    cout << min(n / 2, ans) << endl;
}