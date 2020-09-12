#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	
	int a, f, c;
	scanf("%d %d %d", &a, &f, &c);
	if (!c && a != f)puts("NO");
	else if (!c)puts("YES");
	else if (f < a && c > 0)puts("NO");
	else if (f > a && c < 0)puts("NO");
	else puts(1.0* (f - a) / c == (f - a) / c ? "YES": "NO");
	return 0;
}
