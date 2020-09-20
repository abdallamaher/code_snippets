#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t; cin >> t;
	while (t--) {
		string s; int n; cin >> n >> s;
		int f = 0;
		if (n & 1) {
			for (int i=0; i < n; i+=2)
				if ((s[i] - '0') & 1)f = 1;
			puts(f ? "1" : "2");
		}
		else {
			for (int i = 1; i < n; i += 2)
				if ((s[i] - '0') & 1 ^ 1)f = 1;
			puts(f ? "2" : "1");
		}
	}
	return 0;
}