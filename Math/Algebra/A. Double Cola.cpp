#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	string ar[] = { "Howard", "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
	int n; scanf("%d", &n);
	int i = 0;
	while (n - (5 * (1 << i)) >= 0) {
		n -= 5 * (1 << i);
		++i;
	}
	cout << ar[(n + (1 << i)-1) / (1<<i)];
	return 0;
}