#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        string s; cin >> s;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            int g = i - 1;
            if (g < 0)g = n - 1;

            if (s[i] == '-') a++;
            else if (s[g] == '-')a++;

            if (s[i] == '>' || s[i] == '-') {
                b++;
            }
            if (s[i] == '<' || s[i] == '-') {
                c++;
            }
        }
        if (b == n || c == n) cout << n << '\n';
        else cout << a << '\n';

        cerr << "\n********\n";
    }

    return 0;
}