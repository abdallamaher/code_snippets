#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; cin >> n;
    if (n & 1)return cout << 0, 0;
    n /= 2;
    cout << (n + 1) / 2 - 1 << endl;
}