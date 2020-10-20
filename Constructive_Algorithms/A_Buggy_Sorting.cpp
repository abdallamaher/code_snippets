#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; cin >> n;
    if (n < 3)cout << -1;
    else {
        cout << "3 2 1 ";
        for (int i = 4; i <= n; i++) {
            cout << i << ' ';
        }
    }
    return 0;
}