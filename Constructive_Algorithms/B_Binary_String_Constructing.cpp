#include <bits/stdc++.h>
using namespace std;


int main() {
    int a, b, x; scanf("%d%d%d", &a, &b, &x);
    int f = 0;
    if (b > a)swap(a, b), f = 1;

    string s = "0";
    for (int i = 0;i < x - 1; i++) {
        if (i & 1 ^ 1)s += '1';
        else s += '0';
    }

    string zeros = string(a - (s.size() + 1) / 2, '0');
    string ones = string(b - s.size() / 2, '1');
    string ans;

    if (s.back() == '1' && b > s.size() / 2) {
        ans = '1' + zeros + s + ones;
        ans.pop_back();
    }
    else if (s.back() == '1') {
        for (auto& it : s)it = char('1' - it + '0');
        ans = zeros + s + ones;
    }
    else ans = zeros + s + ones;

    if (f)for (auto& it : ans)it = char('1' - it + '0');
    cout << ans << endl;
    return 0;
}