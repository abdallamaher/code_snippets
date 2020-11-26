#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
	while (t--) {
        int m, n;
		cin >> n >> m;
		int f = 0;
		while (n--) {
			int a, b, c, d; 
            cin >> a >> b >> c >> d;
			if (b == c)f++;
		}
        if(m&1)
            puts("NO");
		else 
            puts(f ? "YES" : "NO");
	}

	return 0;
}