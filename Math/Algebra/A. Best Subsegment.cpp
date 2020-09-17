#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
#ifdef LOCAL   
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	vector<int> v(n, 0);
	int mx = 0;
	for (auto&it : v){
		scanf("%d", &it);
		mx = max(it, mx);
	}
	int cnt = 0, ans = 0;
	for (auto it : v) {
		if (mx == it)cnt++;
		else cnt = 0;
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}