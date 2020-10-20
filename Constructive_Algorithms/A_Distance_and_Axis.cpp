#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int t; cin >> t;
    while (t--) {
        int a, k; cin >> a >> k;
        if (k > a)cout << k - a << '\n';
        else if (k%2 == a%2)cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}