#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll go(int n) {
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int n; cin >> n;
    cout << go(n - 1) / (n / 2) << endl;
    return 0;
}