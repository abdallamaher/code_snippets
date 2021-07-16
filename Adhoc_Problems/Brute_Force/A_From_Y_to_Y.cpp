#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    if (n == 0) {
        cout << 'a';
        return;
    }
    vector<ll> Data;
    for (ll i = 0; i <= 10000; i++) {
        Data.push_back((i - 1) * i / 2);
    }
    int c = 0;
    while (n > 0) {
        auto p = upper_bound(Data.begin(), Data.end(), n) - Data.begin();
        p--;
        for (int i = 0; i < p; i++) {
            cout << char('a' + c);
        }
        c++;
        n -= Data[p];
    }
}

int main() {
    int n; cin >> n;
    if (n == 0) {
        cout << 'a';
        return 0;
    }
    int c = 0;
    string s;
    for (ll i = 1005; i >= 2; i--) {
        ll t = (i - 1) * i / 2;
        while (n >= t) {
            for (int j = 0; j < i; j++)s += char('a' + c);
            n -= t;
            c++;
        }
    }
    cout << s << endl;
    return 0;
}