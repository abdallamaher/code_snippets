#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int ar[200] = {};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", ar + i);
	}
	sort(ar, ar + n);
	int mx = ar[n - 1], mx2 = 0;
	int mark[100000] = {};
	for (int i = 0; i < n; i++) {
		if (!mark[ar[i]] && mx%ar[i] == 0) {
			mark[ar[i]] = 1;
		}
		else if(ar[i] > mx2){
			mx2 = ar[i];
		}
	}
	printf("%d %d\n", mx2, mx);
	return 0;
}