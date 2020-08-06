#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ar[7];
int sum, f;
int vis[7];

bool solve(int i = 0, int sum = 0) {
	if (i == 5)return sum == 23;
	int r = 0;
	for (int j = 0; j < 5; ++j) {
		if (vis[j])continue;
		vis[j] = 1;

		if (i > 0) {    //not first
			r |= solve(i + 1, sum + ar[j]);
			r |= solve(i + 1, sum - ar[j]);
			r |= solve(i + 1, sum * ar[j]);
		}
		else
			r |= solve(i + 1, ar[j]);
		vis[j] = 0;
	}
	return r;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (1) {
		for (int i = 0; i < 5; ++i) {
			cin >> ar[i];
			sum += ar[i];
		}
		if (!sum)return 0;
		if (solve())puts("Possible");
		else puts("Impossible");
		sum = 0, f = 0;
	}

	return 0;
}
