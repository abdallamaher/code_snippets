#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

int n, m, r, l, down, cnt;
int ar[N], b[N], a[N];

int main() {
	cin.sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < n; i++) {
		if (down && ar[i] < ar[i + 1]) {
			a[i] = cnt;
			b[i] = cnt;
			cnt++;
			if (ar[i] < ar[i + 1])b[i] = cnt;
			for (int j = i - 1; j >= 0; j--) {
				if (ar[j] == ar[i])b[j] = cnt;
				else break;
			}
			down = 0;
		}
		else if (ar[i] <= ar[i + 1]) {
			a[i] = cnt;
			b[i] = cnt;
		}
		else if (ar[i] > ar[i + 1]) {
			down = 1;
			a[i] = cnt;
			b[i] = cnt;
		}
	}
	while (m--) {
		cin >> l >> r;
		l--, r--;
		int p1 = upper_bound(b, b + n, b[l]) - b;
		int p2 = upper_bound(a, a + n, a[p1-1]) - a;
		if (p2-1 >= r)puts("Yes");
		else puts("No");
	}
	return 0;
}



/*
small_test_case
13 1
1 2 1 2 8 8 8 9 7 7 7 7 8
*/

 


