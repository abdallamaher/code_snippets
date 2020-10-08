#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    string s; cin >> s;
    s = '#' + s;
    int ans = 0;
    for (int i = 1, cnt = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1] || cnt == 5)ans++, cnt = 1;
        else cnt++;
    }
    cout << ans;

    /*
    int ans = 0; char cur = s[0];
    for (int i = 0, cnt = 0; i < s.size(); i++) {
 
        if (s[i] == cur)cnt++;
        else {
            cnt = 1;
            ans++;
            cur = s[i];
        }
 
        if (i == s.size() - 1 || cnt == 5)++ans, cnt = 0, cur = s[i + 1];
 
        //cout << i << ' ' << cur << ' ' << ans << endl;
    }
    */
    return 0;
}