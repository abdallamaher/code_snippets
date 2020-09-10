#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, n, d;

bool go(int x) {
	int tmp = x + (d + x) / (x + 1);
	return n >= tmp;
}

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &d);
		int f = 0;
		for (int i = 0; i*i <= d; i++) {
			if (go(i))f = 1;
			if (i && go(d/i))f = 1;
			if (f)break;
		}
		puts(f ? "YES" : "NO");
	}
	return 0;
}