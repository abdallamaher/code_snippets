#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n; scanf("%d", &n);
	if ((n & 1) || (n == 2))puts("NO");
	else puts("YES");
	return 0;
}