#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int cnt2 = 0, cnt3 = 0;

		// start prime_factoritazion
		while (n%2 == 0) {
			++cnt2;
			n /= 2;
		}
		while (n%3 == 0) {
			++cnt3;
			n /= 3;
		}

		if (n == 1 && cnt3 >= cnt2) printf("%d\n", cnt3 - cnt2 + cnt3);
		else puts("-1");
	}
	return 0;
}