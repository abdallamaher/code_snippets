#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s, ss;
    cin >> s;
    cin >> ss;
    
	int n = s.size(), m = ss.size();
    int x = abs(n - m); string st(x, '0');
    if (n < m) s = st + s, n = m;	// concatination works in liner time o(n)
    if (n > m) ss = st + ss, m = n;	// if x > 1e6 should use (ostringstream)

    int f = 0;
    for (int i = 0; i < n && !f; i++) {
        if (s[i] > ss[i]) {
            f = 1;
        } else if (s[i] < ss[i]) {
            f = 2;
        }
    }
    if (f)
        puts(f == 1 ? ">" : "<");
    else
        puts("=");
    return 0;
}