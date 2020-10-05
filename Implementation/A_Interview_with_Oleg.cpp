#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; scanf("%d", &n);
    string s; cin >> s;
    string ans;
    for (int i = 0, f = 0, flag = 0; i < n; i++) {
        if (s[i] == 'o') {
            f = 1, flag = 1;
            ans += s[i];
        }
        else if (f && s[i] == 'g' && s[i + 1] == 'o') {
            ++i;
            if (flag) {
                flag = 0;
                ans.pop_back();
                ans += "***";
            }
        }
        else {
            f = 0;
            ans += s[i];
        }
    }
    cout << ans << endl;
    return 0;
}