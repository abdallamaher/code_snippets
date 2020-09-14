#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif

	int n; scanf("%d", &n);
	vector<int> v(n + 5, 0);
	bool even = true;
	for(int i=1; i<=n; i++) {
		scanf("%d", &v[i]);
		v[i] += v[i - 1];
		even &= bool(v[i] & 1 ^ 1);
	}
	if (even)puts("Second");
	else puts("First");
	return 0;
}
