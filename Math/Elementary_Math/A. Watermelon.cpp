#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n; scanf("%d", &n);
	for (int i = 2; i < n; i += 2) {
		if ((n - i) & 1 ^ 1)return puts("YES");
	}
	puts("NO");
	return 0;
}
