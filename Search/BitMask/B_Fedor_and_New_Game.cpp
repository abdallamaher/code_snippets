#include <bits/stdc++.h>
using namespace std;
#define ll long long

string binary_string(int n) {
    string s;
    while (n) {
        s += (n & 1) ? '1' : '0';
        n >>= 1;
    }
    while (s.size() < 25)s += '0';
    return s;
}

int main() {
    int s, p, k; cin >> s >> p >> k;
    vector<int> ar(p + 1);
    for (auto& it : ar)cin >> it;
    int player = ar.back();
    int ans = 0;
    for (int i = 0; i < p;i++) {
        int t = ar[i];
        int cnt = 0;
        for (int x = 0;x < 25;x++) {
            if ((t & (1 << x)) != (player & (1 << x)))cnt++;
        }
        if (cnt <= k)ans++;
    }
    cout << ans << endl;
}