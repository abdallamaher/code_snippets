#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, k, f;

int main() {
	cin.sync_with_stdio(false);
	cin >> n >> k;
	if (k < n / 2 || (n == 1 && k))return puts("-1"), 0;
	if (n == 1)return puts("1"), 0;
	if (n & 1) {
		n--;
		f = 1;
	}
	int x = k - (n - 2) / 2;
	if (x) {
		printf("%d ", x);
		printf("%d ", x * 2);
	}
	k -= x;
	for (int i = x * 2 + 1; k; i+=2, k--) {
		printf("%d ", i);
		printf("%d ", i + 1);
	}
	if (f) printf("%d ", (int)1e9);
	return 0;
}














