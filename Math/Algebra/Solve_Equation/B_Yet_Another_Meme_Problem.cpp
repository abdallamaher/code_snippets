#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int a, b; cin >> a >> b;
    /*
    b + 1 = 10^|b|
    a * (b+1) = a * 10^|b|
    */
    ll tmp = 0;
    ll ans = 0;
    while (tmp * 10 + 9 <= b)ans++, tmp = tmp * 10 + 9;

    cout << ans * a << endl;
}

void run(){
    int a, b; cin >> a >> b;
    // count 9 99 999 under number b
    // problem in {4, 9} so if 9 + 1= 10  same 99 + 1 = 1000
    string bb = to_string(b + 1);
    ll num = bb.size() - 1;
    cout << num * a << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)run();
}