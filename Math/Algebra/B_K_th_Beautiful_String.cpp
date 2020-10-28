#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);
        int i = n;
        for (; i > 0; i--) {
            if (n - i >= k)break;
            k -= n - i;
        }
        string s(n, 'a');
        s[i - 1] = 'b';
        s[n - k] = 'b';
        cout << s << endl;
    }
    return 0;
}