#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, n; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int mxl = 0, mnr = 1e9;
		while (n--) {
			int l, r; scanf("%d %d", &l, &r);
			mxl = max(mxl, l);
			mnr = min(mnr, r);
		}
		printf("%d\n", max(0, mxl - mnr));
	}
	return 0;
}

/*
1
4
2 2
1 3
4 5 
7 8
*/