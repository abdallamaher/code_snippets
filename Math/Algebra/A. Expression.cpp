#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int ans = 0;
	if (a > c)swap(a, c);
	if (a == 1 || b == 1)ans = a + b;
	else ans = a * b;

	if (c == 1)ans++;
	else ans *= c;
	printf("%d\n", ans);
	return 0;
}