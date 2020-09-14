#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	scanf("%d %d", &n, &k);
	int ar[105] = {};
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		ar[s.size()]++;
	}
	string ss; cin >> ss;
	int mxS = ss.size();
	int sum = 0;
	for (int i = 0; i < mxS; i++) {
		sum += ar[i];
	}
	int mn = sum / k * 5 + sum + 1;
	sum += ar[mxS];
	int mx = (sum - 1) / k * 5 + sum;
	printf("%d %d\n", mn, mx);
	return 0;
}
