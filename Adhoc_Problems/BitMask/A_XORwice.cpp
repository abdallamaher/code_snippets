#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int a, b; cin >> a >> b;
    cout << (a ^ b) << endl;
}

inline void run() {
    int a, b; cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < 30;i++) {
        int bit_a = (a & (1 << i));
        int bit_b = (b & (1 << i));
        if (bit_a || bit_b)ans |= (1 << i);
    }
    cout << (a ^ ans) + (b ^ ans) << endl;
}

string to_binary(int n) {
    string s;
    while (n > 0) {
        s += (n & 1) ? '1' : '0';
        n >>= 1;
    }
    while (s.size() < 30)s += '0';
    // reverse(s.begin(), s.end());
    return s;
}

inline void go() {
    int a, b; cin >> a >> b;
    string s = to_binary(a);
    string t = to_binary(b);
    int ans = 0;
    for (int i = 0;i < 30;i++) {
        if (s[i] != t[i]) {
            ans = (ans | (1 << i));
        }
    }
    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    while (t--)run();
}