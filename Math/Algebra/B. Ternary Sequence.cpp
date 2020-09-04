#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		int z, o, tw;
		scanf("%d %d %d", &z, &o, &tw);
		int zz, oo, tww;
		scanf("%d %d %d", &zz, &oo, &tww);
		int sum = 0;

		sum += min(oo, tw) * 2;	// Max plus operation
		tw -= min(oo, tw);	

		tww -= min(z, tww);	// Min minus operation
		tww -= min(tw, tww);
		sum -= tww * 2;

		printf("%d\n", sum);

	}
	return 0;
}