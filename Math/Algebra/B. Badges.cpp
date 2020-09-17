#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int a, b, k;
	scanf("%d%d%d", &a, &b, &k);
	int cnt = min(a, k) + 1;
	int cntStartFrom = max(k - b, 0);
	printf("%d", cnt - cntStartFrom);
	return 0;
}