#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    string x, y; cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    /*
    001    +
    001
    010
    */
    int a = y.find('1');
    int b = x.find('1', a);

    cout << (b - a) << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}