#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int t; cin >> t;
    while (t--) {
        int n, a, b; scanf("%d %d %d", &n, &a, &b);
        string s(n, 'a');
        for (int i = 0, j = 0; i < n; i++, j++) {
            s[i] += (j % b);
        }
        cout << s << endl;
    }
    return 0;
}