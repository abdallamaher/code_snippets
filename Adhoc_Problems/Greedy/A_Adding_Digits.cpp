#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n, a, b; cin >> a >> b >> n;
    int ok = 0;
    for (int i = 0; i < 10; i++) {
        if ((a * 10 + i) % b == 0) {
            a = a * 10 + i;
            ok = 1;
            break;
        }
    }
    if (ok)cout << a << string(n - 1, '0') << endl;
    else cout << -1;
}